#include <bits/stdc++.h>
using namespace std;
const long long NN = 1e10 + 7;
const int N = 1e5 + 7;
const int M = 30;
const long long mod = 1e9 + 7;
const long long inf = 1e18 + 7;
const double long rf = 1e-14;
const int B = sqrt(N);
int n;
int a[N];
int b[N];
bool used[N];
vector<int> v[N], ans;
void dfs(int x, int a1, int b1) {
  if (used[x]) return;
  used[x] = true;
  swap(a1, b1);
  if (a1) a[x] ^= 1;
  if (a[x] != b[x]) {
    a1 += 1;
    ans.push_back(x);
  }
  for (auto y : v[x]) {
    dfs(y, a1, b1);
  }
}
void solve1() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  dfs(1, 0, 0);
  cout << (int)ans.size() << "\n";
  for (auto x : ans) {
    cout << x << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int cghf = 1;
  while (cghf--) {
    solve1();
  }
}
