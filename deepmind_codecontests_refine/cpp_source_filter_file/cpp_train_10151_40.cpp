#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
const int inf = 1000000000;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long t, w, b;
  int resp = 0;
  scanf("%lld %lld %lld", &t, &w, &b);
  long long aux = gcd(w, b);
  long long tmp = gcd(w, aux);
  long long lcm = w / tmp;
  aux /= tmp;
  tmp = gcd(b, aux);
  lcm *= b / tmp;
  long long mn = min(w, b);
  long long per = 0;
  long long qtd = t;
  if (log(w) + log(b) - log(gcd(w, b)) <= 18 * log(10)) {
    per = t / lcm;
    qtd = t % lcm;
  }
  resp += (per)*mn;
  resp += min(mn, qtd + 1);
  resp--;
  long long g = gcd(resp, t);
  long long a = resp / g;
  long long k = t / g;
  printf("%lld/%lld\n", a, k);
}
