#include <bits/stdc++.h>
using namespace std;
inline void file() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  if (0) {
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
  }
}
const int px[5] = {0, 0, 1, -1}, py[5] = {-1, 1, 0, 0}, N = 2e5 + 100,
          INF = 1e9, M0 = 1e8, M1 = 1e9;
const long double eps = 1e-6, PI = 3.14159265358979323846;
int n, a[N];
int main() {
  file();
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i <= n / 2; ++i)
    if (!(i & 1)) swap(a[i], a[n - i - 1]);
  for (int i = 0; i < n; ++i) cout << a[i] << ' ';
}
