#include <bits/stdc++.h>
using namespace std;
long long a, b;
long long get(long long p) {
  long long res = (a - p + 1) * (a - p + 1) + p - 1;
  long long q = b / (p + 1);
  long long r = b % (p + 1);
  res -= r * (q + 1) * (q + 1);
  return res - (p + 1 - r) * q * q;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> a >> b;
  if (b < 2) {
    cout << a * a - b * b << endl;
    for (long long i = 0; i < a; i++) cout << 'o';
    if (b) cout << 'x';
    cout << endl;
    return 0;
  }
  if (a == 0) {
    cout << -b * b << endl;
    for (long long i = 0; i < b; i++) cout << 'x';
    cout << endl;
    return 0;
  }
  long long p = b - 1;
  if (a < p) p = a;
  long long max = -b * b;
  long long maxp = 0;
  for (long long i = 1; i <= p; i++) {
    long long c = get(i);
    if (c > max) {
      max = c;
      maxp = i;
    }
  }
  cout << max << endl;
  long long q = b / (maxp + 1);
  long long r = b % (maxp + 1);
  for (long long i = 0; i <= maxp; i++) {
    for (long long j = 0; j < q; j++) cout << 'x';
    if (i < r) cout << 'x';
    if (i == 0) {
      for (long long j = 0; j < a - maxp + 1; j++) cout << 'o';
    } else if (i < maxp) {
      cout << 'o';
    }
  }
  cout << endl;
  return 0;
}
