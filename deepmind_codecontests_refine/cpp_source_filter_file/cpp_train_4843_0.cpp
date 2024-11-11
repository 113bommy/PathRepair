#include <bits/stdc++.h>
using namespace std;
void fre() {
  freopen("c://test//input.in", "r", stdin);
  freopen("c://test//output.out", "w", stdout);
}
template <class T1, class T2>
inline void gmax(T1 &a, T2 b) {
  if (b > a) a = b;
}
template <class T1, class T2>
inline void gmin(T1 &a, T2 b) {
  if (b < a) a = b;
}
const int N = 1e5 + 10, M = 0, Z = 1e9 + 7, ms63 = 0x3f3f3f3f;
long long n, m;
long long A, cf, cm;
long long sum[N];
struct Skill {
  long long v, o;
} a[N];
bool cmp1(Skill a, Skill b) { return a.v < b.v; }
bool cmp2(Skill a, Skill b) { return a.o < b.o; }
int solve(int R, long long now) {
  if (R == 0) return A;
  int l = 1;
  int r = R;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    long long need = a[mid].v * mid - sum[mid];
    if (need > now)
      r = mid - 1;
    else
      l = mid;
  }
  long long need = a[l].v * l - sum[l];
  long long more = (now - need) / R;
  return min(A, a[l].v + more);
}
int main() {
  while (~scanf("%lld%lld%lld%lld%lld", &n, &A, &cf, &cm, &m)) {
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i].v);
      a[i].o = i;
    }
    sort(a + 1, a + n + 1, cmp1);
    a[n + 1].v = A;
    for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i].v;
    long long ans = -1;
    long long cost = 0;
    int v, p;
    for (int i = n; i >= 0; --i) {
      cost += A - a[i + 1].v;
      if (cost > m) break;
      long long minv = solve(i, m - cost);
      long long tmp = minv * cm + (n - i) * cf;
      if (tmp > ans) {
        ans = tmp;
        p = i;
        v = minv;
      }
    }
    printf("%lld\n", ans);
    for (int i = n; i > p; --i) a[i].v = A;
    for (int i = 1; i <= p; ++i) gmax(a[i].v, v);
    sort(a + 1, a + n + 1, cmp2);
    for (int i = 1; i <= n; ++i) printf("%lld ", a[i].v);
    puts("");
  }
  return 0;
}
