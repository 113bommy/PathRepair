#include <bits/stdc++.h>
using namespace std;
int stmp;
const int MAX = 100000;
const unsigned long long INF = 1000000000000000010LL;
int A[MAX];
int B[MAX];
int n, c;
unsigned long long op(unsigned long long a, unsigned long long b,
                      unsigned long long d) {
  unsigned long long res = 0;
  res += (a / d) * (b / d) * d;
  res += (a / d) * (b % d);
  res += (b / d) * (a % d);
  res += ((a % d) * (b % d)) / d;
  return res;
}
unsigned long long solve(unsigned long long x) {
  unsigned long long d = 0;
  for (int i = 0; i < (n); ++i) d += op(x, A[i], B[i]) + 1;
  return d;
}
unsigned long long bin1() {
  unsigned long long p = 1, q = INF;
  while (p < q) {
    unsigned long long r = (p + q) / 2;
    if (solve(r) > (unsigned long long)c)
      q = r - 1;
    else
      p = r + 1;
  }
  return p;
}
unsigned long long bin2() {
  unsigned long long p = 1, q = INF;
  while (p < q) {
    unsigned long long r = (p + q) / 2;
    if (solve(r) < (unsigned long long)c)
      p = r + 1;
    else
      q = r - 1;
  }
  return p;
}
int main(int argc, char *argv[]) {
  stmp = scanf("%d %d", &n, &c);
  for (int i = 0; i < (n); ++i) stmp = scanf("%d %d", A + i, B + i);
  unsigned long long res = bin1() - bin2();
  if (res + 1 == INF)
    cout << -1 << endl;
  else
    cout << res << endl;
  return 0;
}
