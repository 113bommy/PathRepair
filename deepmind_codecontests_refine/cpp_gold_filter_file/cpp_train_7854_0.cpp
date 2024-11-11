#include <bits/stdc++.h>
using namespace std;
const int NO = 5005;
struct X {
  int a, b;
} p[NO];
bool S(const X &a, const X &b) {
  if (a.a != b.a) return a.a < b.a;
  return a.b < b.b;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].a, &p[i].b);
  sort(p + 1, p + 1 + n, S);
  int ans = min(p[1].a, p[1].b);
  for (int i = 2; i <= n; i++)
    if (ans <= p[i].b)
      ans = p[i].b;
    else
      ans = p[i].a;
  printf("%d", ans);
  return 0;
}
