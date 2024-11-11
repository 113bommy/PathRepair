#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool Cmin(T &x, T y) {
  return x > y ? x = y, 1 : 0;
}
const long long inf = 1e18;
const int maxn = 2e5 + 50;
long long an;
long long a[maxn];
int n;
map<long long, int> prime;
inline unsigned long long Rand() {
  static unsigned long long seed = 0;
  seed ^= rand();
  seed ^= seed << 13;
  seed ^= seed >> 17;
  seed ^= seed << 5;
  return seed;
}
void work(long long x) {
  if (x == 0) return;
  for (int i = 2; i <= x / i; ++i)
    if (x % i == 0) {
      prime[i] = 1;
      while (x % i == 0) x /= i;
    }
  if (x > 1) prime[x] = 1;
}
long long sol(long long x) {
  long long an = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] <= x)
      an += x - a[i];
    else
      an += min(a[i] % x, x - a[i] % x);
  }
  return an;
}
int main() {
  srand((unsigned long long)(new char));
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d", &a[i]);
  }
  long long an = inf;
  int T = 20;
  while (T--) {
    int x = Rand() % n + 1;
    prime.clear();
    work(a[x]), work(a[x] - 1), work(a[x] + 1);
    for (map<long long, int>::iterator it = prime.begin(); it != prime.end();
         ++it) {
      Cmin(an, sol(it->first));
    }
  }
  printf("%I64d\n", an);
  return 0;
}
