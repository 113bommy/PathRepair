#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6 + 7;
const int Inf = 1e9 + 7;
long long N, M;
int Q;
long long Gcd(long long a, long long b) {
  if (b == 0LL)
    return a;
  else
    return Gcd(b, a % b);
}
int main() {
  long long sx, Sy, ex, Ey;
  scanf(" %lld %lld %d", &N, &M, &Q);
  long long gcd = Gcd(N, M);
  long long dN = N / gcd, dM = M / gcd;
  while (Q--) {
    scanf(" %lld %lld %lld %lld", &sx, &Sy, &ex, &Ey);
    long long tmp1, tmp2;
    if (sx == ex) {
      if (sx == 1) {
        tmp1 = Sy / dN + (Sy % dN != 0 ? 1 : 0);
        tmp2 = Ey / dN + (Ey % dN != 0 ? 1 : 0);
      } else {
        tmp1 = Sy / dM + (Sy % dM != 0 ? 1 : 0);
        tmp2 = Ey / dM + (Ey % dM != 0 ? 1 : 0);
      }
    } else {
      if (sx == 1) {
        tmp1 = Sy / dN + (Sy % dN != 0 ? 1 : 0);
        tmp2 = Ey / dM + (Ey % dM != 0 ? 1 : 0);
      } else {
        tmp1 = Sy / dM + (Sy % dM != 0 ? 1 : 0);
        tmp2 = Ey % dN + (Ey % dN != 0 ? 1 : 0);
      }
    }
    if (tmp1 == tmp2) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}
