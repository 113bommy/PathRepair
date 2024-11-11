#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
long long n, m, pp[N], ans[N];
long long t;
struct ANT {
  long long pos, dir, id;
  bool operator<(const ANT &d) const { return pos < d.pos; }
} ant[N];
long long Get(long long x) {
  if (ant[x].dir == -1) {
    return (t - ant[x].pos + m - 1) / m;
  } else {
    return (t + ant[x].pos) / m;
  }
}
int main() {
  scanf("%lld%lld%lld", &n, &m, &t);
  for (long long i = 0; i < n; ++i) {
    scanf("%lld", &ant[i].pos);
    --ant[i].pos;
    char dd = getchar();
    while (dd == ' ') dd = getchar();
    ant[i].dir = (dd == 'L') ? -1 : 1;
    ant[i].id = i;
  }
  sort(ant, ant + n);
  for (long long i = 0; i < n; ++i)
    pp[i] = ((t * ant[i].dir + ant[i].pos) % m + m) % m;
  sort(pp, pp + n);
  long long bg = 0;
  for (long long i = 0; i < n; ++i) bg = (Get(i) + bg) % n;
  bg = (bg + n) % n;
  for (long long i = bg, j = 0; j < n; ++j, i = (i + 1) % n)
    ans[ant[i].id] = pp[j];
  for (long long i = 0; i < n; ++i) printf("%lld ", ans[i] + 1);
  printf("\n");
  return 0;
}
