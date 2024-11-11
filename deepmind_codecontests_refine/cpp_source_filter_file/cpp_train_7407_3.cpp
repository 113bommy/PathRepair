#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const int INF = (int)2e9;
const int MINF = (int)-2e9;
const long long MOD = (long long)1e9 + 7;
const long long LINF = (long long)4e18;
const long long MLINF = (long long)-4e18;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
string to_string(int num) {
  ostringstream ost;
  ost << num;
  return ost.str();
}
bool isSimple(int a) {
  int limit = floor(sqrt((double)a));
  for (int i = 2; i <= limit; i++)
    if (a % i == 0) return false;
  return true;
}
vector<vector<int> > tree;
int n;
vector<bool> used;
int dfs(int v, int count) {
  if (tree[v].size() == 1) return count + 1;
  int Max = MINF;
  for (int i = 0; i < (int)tree[v].size(); i++)
    Max = max(Max, dfs(tree[v][i], count + 1));
  return Max;
}
int main() {
  if (!true) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  cin >> n;
  for (int i = 0; i < n + 1; i++) {
    vector<int> tmp;
    tree.push_back(tmp);
    used.push_back(false);
  }
  for (int i = 1; i <= n; i++) {
    int tmp;
    cin >> tmp;
    if (tmp != -1) tree[tmp].push_back(i);
  }
  int Max = MINF;
  for (int i = 1; i <= n; i++) Max = max(Max, dfs(i, 1));
  cout << Max << endl;
  return 0;
}
