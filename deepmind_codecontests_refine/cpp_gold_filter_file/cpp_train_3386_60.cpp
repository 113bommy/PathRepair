#include <bits/stdc++.h>
using namespace std;
struct yts {
  long long x, y;
} t[200010], st[200010];
yts operator-(yts x, yts y) { return (yts){x.x - y.x, x.y - y.y}; }
double operator*(yts x, yts y) { return (double)x.x * y.y - x.y * y.x; }
int n, top;
long long sum, ans, a[200010], Sum[200010];
bool cmp(yts x, yts y) { return x.x < y.x || (x.x == y.x && x.y < y.y); }
void tubao() {
  sort(t + 1, t + n + 1, cmp);
  top = 1;
  st[1] = t[1];
  for (int i = 2; i <= n; i++) {
    while (top > 1 && (t[i] - st[top]) * (st[top] - st[top - 1]) <= 0) top--;
    st[++top] = t[i];
  }
}
long long calc(int i, long long x) { return x * st[i].x + st[i].y; }
int query(long long x) {
  int l = 1, r = top, ans = 0;
  while (r - l >= 3) {
    int mid = l + (r - l) / 3, midmid = r - (r - l) / 3;
    long long ans1 = calc(mid, x);
    long long ans2 = calc(midmid, x);
    if (ans1 > ans2)
      r = midmid;
    else
      l = mid;
  }
  ans = l;
  for (int i = l + 1; i <= r; i++)
    if (calc(i, x) > calc(ans, x)) ans = i;
  return ans;
}
int main() {
  scanf("%d", &n);
  sum = 0;
  for (int i = 1; i <= n; i++) {
    long long x;
    scanf("%I64d", &x);
    Sum[i] = Sum[i - 1] + x;
    t[i].x = i;
    t[i].y = -Sum[i];
    a[i] = x;
    ans += (long long)x * i;
  }
  sum = ans;
  t[++n].x = 0;
  t[n].y = 0;
  tubao();
  for (int i = 1; i < n; i++) {
    int x = query(a[i]);
    if (st[x].x >= i)
      ans = max(ans, sum + (long long)a[i] * (st[x].x - i) + st[x].y + Sum[i]);
    else
      ans = max(ans, sum + (long long)a[i] * (st[x].x - (i - 1)) + st[x].y +
                         Sum[i - 1]);
  }
  printf("%I64d\n", ans);
  return 0;
}
