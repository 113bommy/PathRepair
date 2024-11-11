#include <bits/stdc++.h>
using namespace std;
const long long N = 100000 + 10;
struct skill {
  long long lv, id;
} sk[N];
long long n, A, cf, cm, m, cost[N], ans, fulls, minlvl;
bool cmp_lv(skill A, skill B) { return A.lv > B.lv; }
bool cmp_id(skill A, skill B) { return A.id < B.id; }
long long minlevel(long long full, long long pts) {
  if (full == n) return A;
  long long lb = full + 1, rb = n, mid = (full + n + 1) / 2;
  for (; lb + 1 < rb; mid = (lb + rb) / 2)
    if (cost[mid] <= pts)
      rb = mid;
    else
      lb = mid;
  if (cost[lb] <= pts)
    mid = lb;
  else
    mid = rb;
  return min(A, sk[mid].lv + (pts - cost[mid]) / (n - mid + 1));
}
int main() {
  cin >> n >> A >> cf >> cm >> m;
  for (long long i = 1; i <= (n); i++) {
    scanf("%I64d", &sk[i].lv);
    sk[i].id = i;
  }
  sort(sk + 1, sk + n + 1, cmp_lv);
  for (long long i = (n - 1); i >= (1); i--)
    cost[i] = cost[i + 1] + (sk[i].lv - sk[i + 1].lv) * (n - i);
  sk[0].lv = A;
  for (long long i = (0); i <= (n); i++) {
    m -= (A - sk[i].lv);
    if (m < 0) break;
    long long tmp = i * cf + cm * minlevel(i, m);
    if (tmp > ans) {
      ans = tmp;
      fulls = i;
      if (i < n)
        minlvl = (tmp - i * cf) / cm;
      else
        minlvl = A;
    }
  }
  printf("%I64d\n", ans);
  for (long long i = 1; i <= (fulls); i++) sk[i].lv = A;
  for (long long i = 1; i <= (n); i++) sk[i].lv = max(sk[i].lv, minlvl);
  sort(sk + 1, sk + n + 1, cmp_id);
  for (long long i = 1; i <= (n); i++) printf("%I64d ", sk[i].lv);
  printf("\n");
  return 0;
}
