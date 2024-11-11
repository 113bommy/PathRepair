#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10, inf = 0x3f3f3f3f, mod = 1000000007;
void read() {}
template <typename T, typename... T2>
inline void read(T &x, T2 &...oth) {
  x = 0;
  int ch = getchar(), f = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  if (f) x = -x;
  read(oth...);
}
long long sum[maxn];
signed main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long n, s;
  cin >> n >> s;
  if (s - (n - 1) <= n - 1)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (int i = 1; i < n; i++) cout << 1 << ' ';
    cout << s - (n - 1) << endl;
    cout << n << endl;
  }
  return 0;
}
