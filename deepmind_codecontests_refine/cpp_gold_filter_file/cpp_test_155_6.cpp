#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int t;
struct node {
  int a, b;
  bool operator<(const node& rhs) const { return a < rhs.a; }
} p0[N], p1[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    int n, p[N], q[N];
    char c[N];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", p + i);
    scanf("%s", c + 1);
    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++) {
      if (c[i] == '0')
        p0[++cnt0].a = p[i], p0[cnt0].b = i;
      else
        p1[++cnt1].a = p[i], p1[cnt1].b = i;
    }
    sort(p0 + 1, p0 + 1 + cnt0);
    sort(p1 + 1, p1 + 1 + cnt1);
    for (int i = 1; i <= cnt0; i++) q[p0[i].b] = i;
    for (int i = 1; i <= cnt1; i++) q[p1[i].b] = i + cnt0;
    for (int i = 1; i <= n; i++) printf("%d ", q[i]);
    printf("\n");
  }
  return 0;
}
