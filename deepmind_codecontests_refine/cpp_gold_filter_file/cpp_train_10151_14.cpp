#include <bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool fail;
unsigned long long mult(unsigned long long x, unsigned long long gc,
                        unsigned long long limit) {
  vector<unsigned long long> vals;
  while (gc) {
    if (gc & 1ULL)
      vals.push_back(1);
    else
      vals.push_back(0);
    gc >>= 1;
  }
  unsigned long long res = 0;
  reverse(vals.begin(), vals.end());
  for (unsigned long long val : vals) {
    res *= 2ULL;
    if (val) res += x;
    if (res > limit) {
      fail = true;
      return 1;
    }
  }
  return res;
}
int main() {
  unsigned long long t = ({
    unsigned long long x;
    scanf("%llu", &x);
    x;
  });
  unsigned long long w = ({
    unsigned long long x;
    scanf("%llu", &x);
    x;
  });
  unsigned long long b = ({
    unsigned long long x;
    scanf("%llu", &x);
    x;
  });
  unsigned long long gc = gcd(w, b);
  unsigned long long wb = mult(w / gc, b, t);
  unsigned long long p = 0;
  if (!fail) {
    unsigned long long moments = t / wb;
    if (moments > 1) p += (moments - 1) * min(w, b);
    if (moments > 0) {
      p += min(t - moments * wb + 1, min(w, b));
    }
  }
  p += min(min(w, b) - 1, t);
  printf("%llu/%llu\n", p / gcd(p, t), t / gcd(p, t));
}
