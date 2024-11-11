#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
void shikhar7s(long long int cas) {
  long long int n, i;
  cin >> n;
  long long int a[n], c[70] = {0}, x, y;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    y = a[i];
    x = 0;
    while (y % 2 == 0) {
      y /= 2;
      x++;
    }
    c[x]++;
  }
  long long int ans = 0, in;
  for (i = 0; i < 70; i++) {
    if (c[i] > ans) {
      ans = c[i];
      in = i;
    }
  }
  cout << n - ans << "\n";
  for (i = 0; i < n; i++) {
    y = a[i];
    x = 0;
    while (y % 2 == 0) {
      y /= 2;
      x++;
    }
    if (x != in) cout << a[i] << " ";
  }
}
signed main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t = 1;
  long long int cas = 1;
  while (cas <= t) {
    shikhar7s(cas);
    cas++;
  }
  return 0;
}
