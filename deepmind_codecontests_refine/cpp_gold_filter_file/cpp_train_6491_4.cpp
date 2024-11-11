#include <bits/stdc++.h>
using namespace std;
const long long A = 100000000000000LL, N = 300005;
long long p, d, limit;
long long cal(long long p) {
  int x = 0;
  if (p % 10 != 9) return 0;
  while (p % 10 == 9) {
    x++;
    p /= 10;
  }
  return x;
}
int main() {
  cin >> p >> d;
  limit = p - d;
  long long j = p;
  long long length = log10(p) + 1;
  long long initial = cal(p);
  int i = 0;
  long long powerr = 10;
  while (true) {
    j = p - p % powerr - 1;
    if (j == -1) break;
    if (j < limit) break;
    powerr *= 10;
  }
  powerr /= 10;
  j = p - p % powerr - 1;
  if (j < limit) j = p;
  if (j >= limit and powerr == 1) j = p;
  if (initial >= (log10(powerr))) j = p;
  cout << j;
}
