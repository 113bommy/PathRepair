#include <bits/stdc++.h>
using namespace std;
long long a, b, w, x, c;
long long g[1005], f[1005], p[1005], nex[1005];
bool check(long long k) {
  long long C = c - k;
  k -= b / x;
  long long B = b % x, A = a;
  if (k > 0) {
    A -= (k / g[B]) * p[B];
    k %= g[B];
    while (k > 0) {
      A--;
      k--;
      if (k == 0) break;
      k -= f[B];
      B = nex[B];
    }
  }
  return C <= A;
}
int main() {
  cin >> a >> b >> w >> x >> c;
  for (int i = 0; i < x; i++) {
    long long state = i - x + w;
    f[i] = state / x;
    nex[i] = state % x;
  }
  for (int i = 0; i < x; i++) {
    long long j = nex[i];
    g[i] = f[i] + 1, p[i] = 1;
    while (j != i) g[i] += f[j] + 1, p[i]++, j = nex[j];
  }
  long long l = 0, h = 2000000000LL;
  while (l + 1 < h) {
    long long m = (l + h) / 2;
    if (check(m))
      h = m;
    else
      l = m + 1;
  }
  if (check(l))
    cout << l;
  else
    cout << h;
}
