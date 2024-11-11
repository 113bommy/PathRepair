#include <bits/stdc++.h>
using namespace std;
void db() { cout << endl; }
template <typename T, typename... U>
void db(T a, U... b) {
  cout << a << ' ', db(b...);
}
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int N = 1000, inf = 1e9 + 1, mod = 1e9 + 7;
int n, k;
int ans[N][N], ma = 0;
void solve(int l, int r, int c) {
  ma = max(ma, c);
  if (r - l < k) {
    for (int i = l; i < r; i++)
      for (int j = i + 1; j <= r; j++) ans[i][j] = c;
    return;
  }
  int len = (r - l + 1) / k;
  if ((r - l + 1) % k) len++;
  for (int st = l; st <= r; st += len) {
    for (int i = st; i < min(r + 1, st + len); i++)
      for (int j = st + len; j <= r; j++) ans[i][j] = c;
    solve(st, min(r, st + len - 1), c + 1);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  solve(0, n - 1, 1);
  cout << ma << '\n';
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) cout << ans[i][j] << ' ';
}
