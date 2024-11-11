#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
struct node {
  int w;
  long long c;
  bool operator<(const node &r) const {
    return c * r.w > r.c * w || c * r.w == r.c * w && w < r.w;
  }
} e[maxn];
long long t[maxn];
long long a[maxn];
int f[maxn];
long long mi[maxn];
bool cmp(long long a, long long b) { return a > b; }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int now1 = 0, now3 = 0;
  for (int i = 1; i <= n; i++) {
    int w;
    long long c;
    scanf("%d%lld", &w, &c);
    if (w == 3)
      t[++now3] = c;
    else
      e[++now1].w = w, e[now1].c = c;
  }
  sort(t + 1, t + 1 + now3, cmp);
  for (int i = 2; i <= now3; i++) t[i] += t[i - 1];
  sort(e + 1, e + 1 + now1);
  int pre = 0;
  mi[0] = 1e18;
  for (int i = 1; i <= now1; i++) {
    a[pre + e[i].w] = a[pre] + e[i].c;
    f[pre + e[i].w] = e[i].w;
    if (e[i].w == 1)
      mi[pre + e[i].w] = e[i].c;
    else
      mi[pre + 1] = mi[pre + 2] = mi[pre];
    pre += e[i].w;
  }
  for (int i = pre + 1; i <= m; i++) a[i] = a[i - 1];
  long long nex1 = 0, nex2 = 0;
  for (int i = pre; i >= 1; i--) {
    if (f[i] == 1)
      nex1 = a[i] - a[i - 1];
    else if (f[i] == 2)
      nex2 = a[i] - a[i - 2];
    else {
      a[i] = max(a[i - 1] + nex1, a[i - 1] + nex2 - mi[i]);
    }
  }
  long long ans = 0;
  for (int i = 0; i <= now3; i++) {
    long long sum = t[i];
    int len = m - i * 3;
    if (len < 0) break;
    sum += a[len];
    ans = max(ans, sum);
  }
  printf("%lld\n", ans);
}
