#include <bits/stdc++.h>
using namespace std;
uint64_t rnd_data = 0xDEADBEEFDULL;
inline void my_srand(int seed) { rnd_data = ((uint64_t)seed << 16) | 0x330E; }
inline int my_rand() {
  rnd_data = rnd_data * 0x5DEECE66DULL + 0xB;
  return (rnd_data >> 17) & 0x7FFFFFFF;
}
template <class _T>
inline _T sqr(const _T &x) {
  return x * x;
}
template <class _T>
inline string tostr(const _T &a) {
  ostringstream os("");
  os << a;
  return os.str();
}
const long double PI = 3.1415926535897932384626433832795L;
const long double EPS = 1e-11;
const int MAXQ = 10240000;
int n, c0, c1;
int q[MAXQ];
void solve2() {
  int cc = c0 + c1;
  long long ans = 0;
  memset((q), 0, sizeof(q));
  int k = 0;
  for (n--; n; k++) {
    while (k < c1 && k % c0) ++k;
    int add;
    if (k < c1) {
      add = 1;
    } else {
      while (!q[k - c1]) ++k;
      add = min(n, q[k - c1]);
    }
    ans += (k + cc) * (long long)add;
    int k1 = k + c0;
    int k2 = k + c1;
    if (k1 >= c1 && k1 - c1 < MAXQ) q[k1 - c1] += add;
    if (k2 >= c1 && k2 - c1 < MAXQ) q[k2 - c1] += add;
    n -= add;
  }
  printf("%lld\n", ans);
}
int main() {
  cout << setiosflags(ios::fixed) << setprecision(10);
  scanf("%d%d%d", &n, &c0, &c1);
  if (c0 > c1) swap(c0, c1);
  if (!c0) {
    printf("%lld\n", c1 * (long long)(n - 1));
    return 0;
  }
  if (c1 / c0 > 1000000) {
    solve2();
    return 0;
  }
  map<long long, long long> q;
  int cc = c0 + c1;
  n--;
  q[0] = 1;
  long long ans = 0;
  long long last = 0;
  while (n) {
    __typeof(q.begin()) it = q.begin();
    long long k = it->first;
    int add = min((long long)n, it->second);
    q.erase(it);
    last = k;
    ans += (k + cc) * (long long)add;
    long long k1 = k + c0;
    long long k2 = k + c1;
    q[k1] += add;
    q[k2] += add;
    n -= add;
  }
  fprintf(stderr, "last = %lld\n", last);
  printf("%lld\n", ans);
  return 0;
}
