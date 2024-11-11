#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10001;
long long a[MAXN];
int f[MAXN];
long long c[MAXN], b[MAXN];
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    long long X = a[i], cnt = 0;
    while (!(X & 1)) {
      ++cnt;
      X >>= 1;
    }
    b[i] = X;
    c[i] = cnt;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    f[i] = 1;
    for (int j = 0; j < i; ++j) {
      if (a[j] % a[i] == 0 && a[i] % 2 == 1) f[i] = max(f[i], f[j] + 1);
      if (a[i] % 2 == 0) {
        long long t1 = b[j], t2 = b[i];
        if (t1 % t2 == 0) {
          if (c[i] - c[j] == i - j || c[i] <= i - j - 1)
            f[i] = max(f[i], f[j] + 1);
        }
      }
    }
    if (f[i] > ans) ans = f[i];
  }
  cout << n - ans;
  return 0;
}
