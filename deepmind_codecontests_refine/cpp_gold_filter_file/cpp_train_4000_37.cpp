#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
long long n, m;
struct node {
  int a, b;
} p[maxn];
bool cmp(node x, node y) { return x.b > y.b; }
int main() {
  long long t, ans;
  long long sum = 0;
  scanf("%I64d %I64d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &p[i].a, &p[i].b);
  }
  for (long long i = 1; i <= m; i++) {
    t = i * (i / 2) + i % 2;
    if (t <= n)
      ans = i;
    else
      break;
  }
  sort(p, p + m, cmp);
  for (long long i = 0; i < ans; i++) {
    sum += (long long)p[i].b;
  }
  printf("%I64d\n", sum);
  return 0;
}
