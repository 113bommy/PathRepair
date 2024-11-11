#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
inline T lowbit(T x) {
  return x & -x;
}
const int N = 2e5 + 10;
int n;
int a[N];
void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  bool flag = false;
  int pos = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0 && a[(i + 1) % n] == 1) {
      flag = true;
      pos = i;
      break;
    }
  }
  if (a[0] == 1) {
    printf("%d ", n + 1);
    for (int i = 1; i <= n; ++i) printf("%d ", i);
    printf("\n");
    return;
  }
  if (a[n - 1] == 1) {
    for (int i = 1; i <= n; ++i) printf("%d ", i);
    printf("%d ", n + 1);
    printf("\n");
    return;
  }
  if (!flag)
    puts("-1");
  else {
    for (int i = 0; i < n; ++i) {
      printf("%d ", i + 1);
      if (pos == i) printf("%d ", n + 1);
    }
    printf("\n");
  }
}
signed main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
