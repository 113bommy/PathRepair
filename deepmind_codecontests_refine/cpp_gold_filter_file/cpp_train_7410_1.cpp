#include <bits/stdc++.h>
using namespace std;
const int NN = 2e5 + 7;
const int N = 1e6 + 7;
const int M = 17;
const int mod = 1e9 + 7;
int n, m;
int used[N];
int ans[N];
bool f = false;
vector<int> v[N];
map<pair<int, int>, int> k;
void dfs(int x, int p) {
  if (used[x]) {
    if (used[x] == 1) {
      f = true;
      ans[k[{p, x}]] = 2;
    }
    return;
  }
  ans[k[{p, x}]] = 1;
  used[x] = 1;
  for (auto y : v[x]) {
    dfs(y, x);
  }
  used[x] = 2;
}
void solve1() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    k[{x, y}] = i;
    v[x].push_back(y);
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      dfs(i, i);
    }
  }
  if (f)
    cout << "2\n";
  else
    cout << "1\n";
  for (int i = 1; i <= m; i++) {
    if (!ans[i]) ans[i] = 1;
    cout << ans[i] << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  int cghf = 1;
  while (cghf--) {
    solve1();
  }
}
