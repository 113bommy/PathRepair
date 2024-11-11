#include <bits/stdc++.h>
using namespace std;
int n;
struct node {
  int a, b;
  bool operator<(const node n) const { return a - b > n.a - n.b; }
} p[(1 << 10)];
int cmp(node n1, node n2) { return n1.b < n2.b; }
int solve(int h, int id) {
  int w = 0, cnt = 0, f[(1 << 10)] = {};
  if (h != p[id].b) f[id] = 1, cnt++;
  for (int i = 1; i <= n; i++)
    if (i != id && p[i].b > h) {
      if (p[i].a > h)
        return (1 << 30);
      else
        cnt++, f[i] = 1;
      if (cnt > n / 2) return (1 << 30);
    }
  for (int i = 1; i <= n; i++) {
    if (f[i] || i == id) continue;
    if (p[i].a > p[i].b && p[i].a <= h && cnt + 1 <= n / 2) f[i] = 1, cnt++;
  }
  for (int i = 1; i <= n; i++)
    if (f[i])
      w += p[i].b;
    else
      w += p[i].a;
  return w * h;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].a, &p[i].b);
  sort(p + 1, p + n + 1);
  int res = (1 << 30);
  for (int i = 1; i <= n; i++) {
    res = min(res, solve(p[i].a, i));
    res = min(res, solve(p[i].b, i));
  }
  cout << res << endl;
  return 0;
}
