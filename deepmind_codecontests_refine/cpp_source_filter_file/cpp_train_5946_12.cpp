#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
struct node {
  int s, t, no;
  long long ans;
} e[maxn];
int n, q;
long long f[maxn];
int a[maxn], len;
bool cmp(node x, node y) { return x.t < y.t; }
long long baoli(node x) {
  int ans = 0;
  for (int i = x.s; i <= n; i += x.t) ans += a[i];
  return ans;
}
void pre(node x) {
  int i;
  for (i = 1; i <= n; i++)
    if (i <= x.t)
      f[i] = a[i];
    else
      f[i] = a[i] + f[i - x.t];
}
bool cmp2(node x, node y) { return x.no < y.no; }
void init() {
  scanf("%d", &q);
  for (int i = 0; i < q; i++) scanf("%d%d", &e[i].s, &e[i].t), e[i].no = i;
  sort(e, e + q, cmp);
  long long ans;
  for (int i = 0; i < q; i++) {
    if (e[i].t > len)
      ans = baoli(e[i]);
    else {
      int aim = (n - e[i].s) / e[i].t * e[i].t + e[i].s;
      if (i == 0 || e[i].t != e[i - 1].t) pre(e[i]);
      if (e[i].s <= e[i].t)
        ans = f[aim];
      else {
        ans = f[aim] - f[max(e[i].s - e[i].t, 0)];
      }
    }
    e[i].ans = ans;
  }
  sort(e, e + q, cmp2);
  for (int i = 0; i < q; i++) cout << e[i].ans << endl;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  len = (int)sqrt(n);
  init();
  return 0;
}
