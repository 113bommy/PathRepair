#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
const int maxn = 1e5 + 10;
using namespace std;
int a[maxn], id[maxn], ord[maxn];
long long cnt[maxn];
int n, A, cf, cm;
long long m;
long long calcul(int ed, int &out) {
  long long now = (n - ed + 1LL) * cf;
  out = A;
  if (ed == 1) return now + (A + 0LL) * cm;
  int L = a[1], R = A + 1;
  while (L < R) {
    int mid = (L + R) >> 1;
    int x = lower_bound(a + 1, a + ed, mid) - a;
    --x;
    long long need = (mid + 0LL) * x - cnt[x];
    if (need <= m)
      L = mid + 1;
    else
      R = mid;
  }
  out = L - 1;
  now += out * (cm + 0LL);
  return now;
}
int main() {
  while (scanf("%d%d%d%d%I64d", &n, &A, &cf, &cm, &m) == 5) {
    for (int i = 1; i <= n; ++i) {
      id[i] = i;
      ord[i] = i;
      scanf("%d", a + i);
    }
    sort(id + 1, id + 1 + n,
         [](const int &i, const int &j) { return a[i] < a[j]; });
    sort(a + 1, a + n + 1);
    cnt[0] = 0;
    for (int i = 1; i <= n; ++i) cnt[i] = cnt[i - 1] + a[i];
    int ed = n + 1;
    for (int i = n; i >= 1; --i)
      if (a[i] >= A) ed = i;
    long long ans = 0;
    pair<int, int> res;
    res.second = ed;
    ans = calcul(ed, res.first);
    while (ed > 1 && m > 0) {
      m -= (A - a[ed - 1]);
      if (m < 0) break;
      int out;
      --ed;
      long long t = calcul(ed, out);
      if (ans < t) {
        ans = t;
        res.first = out;
        res.second = ed;
      }
    }
    printf("%I64d\n", ans);
    for (int i = 1; i <= n; ++i) {
      a[i] = max(a[i], res.first);
    }
    for (int i = res.second; i <= n; ++i) a[i] = A;
    sort(ord + 1, ord + 1 + n,
         [](const int &i, const int &j) { return id[i] < id[j]; });
    for (int i = 1; i <= n; ++i) {
      printf("%d ", a[ord[i]]);
    }
    puts("");
  }
  return 0;
}
