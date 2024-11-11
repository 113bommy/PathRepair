#include <bits/stdc++.h>
using namespace std;
long long n, d, m, l;
bool thoa(long long j1, long long j2) {
  long double l1 = j1;
  l1 /= d;
  long double l2 = j2;
  l2 /= d;
  for (long long i = (long long)l1; i <= (long long)l2; i++)
    if ((i - l1) >= 1e-9 && (l2 - i) >= 1e-9) return true;
  return false;
}
int main() {
  cin >> n >> d >> m >> l;
  bool tot = false;
  for (int i = 1; i < n; i++) {
    long long j1 = ((i - 1) * m + l);
    long long j2 = i * m;
    if (thoa(j1, j2)) {
      j1 = (i - 1) * m + l + 1;
      while (j1 % d) j1++;
      cout << j1;
      tot = true;
      break;
    }
  }
  if (!tot) {
    long long j1 = (n - 1) * m + l + 1;
    while (j1 % d) j1++;
    cout << j1;
  }
  return 0;
}
