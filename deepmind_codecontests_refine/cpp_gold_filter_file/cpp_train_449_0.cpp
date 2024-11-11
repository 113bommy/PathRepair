#include <bits/stdc++.h>
using namespace std;
long long n, f[4005];
struct data {
  long long t, c;
} a[2005];
int main() {
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> a[i].t >> a[i].c, a[i].t++;
  for (int i = 1; i <= 2000; ++i) f[i] = 1e18;
  for (int i = 1; i <= n; ++i) {
    for (int j = n; j >= 0; --j)
      if (j - a[i].t < 0)
        f[j] = min(f[j], a[i].c);
      else
        f[j] = min(f[j], f[j - a[i].t] + a[i].c);
  }
  cout << f[n];
  return 0;
}
