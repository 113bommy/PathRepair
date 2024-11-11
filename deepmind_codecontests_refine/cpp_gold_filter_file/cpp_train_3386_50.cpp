#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
long long ans, t, ans1;
long long a[N], s[N];
struct node {
  long long a, b;
};
node q[N];
long long slope(long long a, node b) { return b.a * a + b.b; }
long long query(long long x) {
  int l = 0, r = t;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (slope(x, q[mid]) <= slope(x, q[mid + 1]))
      l = mid;
    else
      r = mid;
  }
  return slope(x, q[r]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    s[i] = s[i - 1] + a[i];
    ans1 += a[i] * i;
  }
  t = 0;
  for (int r = 2; r <= n; r++) {
    node tmp = (node){r - 1, -s[r - 2]};
    while (t > 1 && (q[t].b - tmp.b) * (q[t].a - q[t - 1].a) <=
                        (q[t - 1].b - q[t].b) * (tmp.a - q[t].a))
      t--;
    q[++t] = tmp;
    ans = max(ans, query(a[r]) - a[r] * r + s[r - 1]);
  }
  t = 0;
  for (int l = n - 1; l >= 1; l--) {
    node tmp = (node){-(l + 1), -s[l + 1]};
    while (t > 1 && (q[t].b - tmp.b) * (q[t].a - q[t - 1].a) <=
                        (q[t - 1].b - q[t].b) * (tmp.a - q[t].a))
      t--;
    q[++t] = tmp;
    ans = max(ans, query(-a[l]) - a[l] * l + s[l]);
  }
  printf("%lld\n", ans + ans1);
  return 0;
}
