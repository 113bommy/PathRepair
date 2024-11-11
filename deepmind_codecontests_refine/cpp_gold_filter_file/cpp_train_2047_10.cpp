#include <bits/stdc++.h>
using namespace std;
template <class T, class T2>
inline void chkmax(T &x, const T2 &y) {
  if (x < y) x = y;
}
template <class T, class T2>
inline void chkmin(T &x, const T2 &y) {
  if (x > y) x = y;
}
const int MAXN = (1 << 20);
int64_t n, m, k;
void read() { cin >> n >> m >> k; }
void solve() {
  if (k < n) {
    cout << k + 1 << " " << 1 << '\n';
    return;
  }
  k -= n;
  m--;
  int r = n - k / m;
  k %= m;
  if (((n - r) & 1)) k = m - k - 1;
  cout << r << " " << k + 2 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  read();
  solve();
  return 0;
}
