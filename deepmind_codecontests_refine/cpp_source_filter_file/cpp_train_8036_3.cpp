#include <bits/stdc++.h>
using namespace std;
const long long llinf = 1987654321987654321;
const int inf = 2000000000;
int q;
long long r, b, k;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%lld %lld %lld", &r, &b, &k);
    if (r > b) swap(r, b);
    long long gcded = gcd(r, b);
    r /= gcded, b /= gcded;
    if (k <= (b - 1 + r) / r)
      puts("REBEL");
    else
      puts("OBEY");
  }
}
