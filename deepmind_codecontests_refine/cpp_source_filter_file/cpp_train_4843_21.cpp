#include <bits/stdc++.h>
using namespace std;
long long num[100005], sum[100005];
struct node {
  long long a, p;
} e[100005];
bool cmp(node x, node y) { return x.a > y.a; }
bool cmp2(node x, node y) { return x.p < y.p; }
int main() {
  long long n, A, cf, cm, m, cnt = 0;
  scanf("%lld%lld%lld%lld%lld", &n, &A, &cf, &cm, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &e[i].a);
    e[i].p = i;
    cnt += e[i].a;
  }
  cnt = cnt + m - A * n;
  if (cnt >= 0) {
    printf("%lld\n", cf * n + cm * A);
    while (n--) {
      printf("%lld ", A);
    }
    printf("\n");
    return 0;
  }
  sort(e + 1, e + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    num[i] += num[i - 1] + A - e[i].a;
    sum[n - i + 1] += sum[n - i + 2] + e[n - i + 1].a;
  }
  long long ans = 0, last, need, pos = 0, pos2 = n + 1, M;
  for (int i = 0; i < n; i++) {
    last = m - num[i];
    if (last < 0) continue;
    int l = i + 1, r = n;
    while (l <= r) {
      int mid = (l + r) >> 1;
      need = (n - mid + 1) * e[mid].a - sum[mid];
      if (need <= last) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    need = (n - r) * e[r + 1].a - sum[r + 1];
    long long tmp = i * cf + e[r + 1].a * cm;
    if (n - i) {
      tmp += (last - need) / (n - i) * cm;
      if (ans < tmp) {
        pos = i;
        ans = tmp;
        pos2 = r + 1;
        M = e[r + 1].a + (last - need) / (n - i);
      }
    } else {
      if (ans < tmp) {
        pos = i;
        pos2 = r + 1;
        ans = tmp;
        M = e[r + 1].a;
      }
    }
  }
  for (int i = 1; i <= pos; i++) {
    e[i].a = A;
  }
  for (int i = pos2; i <= n; i++) {
    e[i].a = M;
  }
  sort(e + 1, e + n + 1, cmp2);
  printf("%lld\n", ans);
  for (int i = 1; i <= n; i++) {
    printf("%lld ", e[i].a);
  }
  printf("\n");
  return 0;
}
