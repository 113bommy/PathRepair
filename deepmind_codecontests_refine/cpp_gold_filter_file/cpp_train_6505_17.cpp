#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long a[n];
  for (int i = 0; i < (n); i++) cin >> a[i];
  long long sum = 0;
  for (int i = 0; i < (n); i++) sum += a[i];
  long long r = sum + n, l = 2;
  long long mid;
  while (l < r) {
    mid = (r + l) / 2;
    long long tmp[n];
    for (int i = 0; i < (n); i++) tmp[i] = a[i];
    long long p = n - 1;
    for (int i = 0; i < (m); i++) {
      while (p >= 0 && tmp[p] == 0) p--;
      long long t = mid - p - 1;
      if (t <= 0) break;
      while (p >= 0 && t - tmp[p] >= 0) {
        t -= tmp[p--];
      }
      if (p >= 0) tmp[p] -= t;
    }
    if (p < 0)
      r = mid;
    else
      l = mid + 1;
  }
  cout << r << endl;
  return 0;
}
