#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 123;
const long long INF = (long long)1e18 + 123;
const int inf = (int)1e9 + 123;
const int MOD = (int)1e9 + 7;
void megaRandom() {
  unsigned int FOR;
  asm("rdtsc" : "=A"(FOR));
  srand(FOR);
}
int h, m, s, t1, t2;
void yes() {
  printf("YES");
  exit(0);
}
void no() {
  printf("NO");
  exit(0);
}
int world[N];
long double A, B, C;
bool can(int lq, int rq) {
  long double l = 1.0 * lq, r = 1.0 * rq;
  if ((l <= A && A <= r) || (l <= B && B <= r) || (l <= C && C <= r)) return 0;
  return 1;
}
int main() {
  megaRandom();
  cin >> h >> m >> s >> t1 >> t2;
  h %= 12;
  t1 %= 12;
  t2 %= 12;
  A = h + m / 60. + s / 3600.;
  B = m / 5.0 + s / 60.;
  C = s / 5.0;
  int x = t1;
  while (1) {
    if (x == t2) yes();
    int to = (x + 1) % 12;
    if (x <= to) {
      if (can(x, to))
        x = to;
      else
        break;
    } else {
      if (can(x, 12) && can(0, to))
        x = to;
      else
        break;
    }
  }
  x = t1;
  while (1) {
    if (x == t2) yes();
    int to = x - 1;
    if (to < 0) to = 11;
    if (x >= to) {
      if (can(to, x))
        x = to;
      else
        break;
    } else {
      if (can(to, 12) && can(0, x))
        x = to;
      else
        break;
    }
  }
  no();
  return 0;
}
