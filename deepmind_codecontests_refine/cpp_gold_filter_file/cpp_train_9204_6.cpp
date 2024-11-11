#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e2 + 42;
const int OFFSET = (int)1e4 + 42;
int n, sz[MAXN], cnt_all = 0;
int a[MAXN][MAXN];
void read() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> sz[i];
    for (int k = 1; k <= sz[i]; k++) cin >> a[i][k];
    cnt_all += sz[i];
  }
}
void solve() {
  int ans_first = 0, ans_second = 0;
  vector<int> vec;
  for (int i = 1; i <= n; i++) {
    for (int p = sz[i]; p > sz[i] / 2 + sz[i] % 2; p--) ans_second += a[i][p];
    for (int p = sz[i] / 2; p >= 1; p--) ans_first += a[i][p];
    if (sz[i] % 2 == 1) vec.push_back(-a[i][sz[i] / 2 + 1]);
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); i++)
    if (i % 2 == 0)
      ans_first += -vec[i];
    else
      ans_second += -vec[i];
  cout << ans_first << " " << ans_second << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  read();
  solve();
  return 0;
}
