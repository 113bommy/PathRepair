#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int INF = 0x7fffffff;
const long long inf = 0x3f3f3f3f;
const double eps = 1e-8;
void f() { return; }
int n, w;
int a[maxn];
pair<int, int> p1[maxn], p0[maxn];
int main() {
  f();
  int n, q;
  scanf("%d%d", &n, &q);
  a[0] = n;
  for (int i = 1; i <= n; i++) a[i] = n - i;
  int n1 = 0, n0 = 0;
  for (int j = 0; j < q; ++j) {
    int t;
    scanf("%d", &t);
    if (t == 0) {
      scanf("%d%d", &p0[n0].first, &p0[n0].second);
      n0++;
    } else {
      scanf("%d%d", &p1[n1].first, &p1[n1].second);
      n1++;
    }
  }
  sort(p1, p1 + n1);
  int pos = 0;
  for (int i = 1; i < n1; i++) {
    if (p1[pos].second >= p1[i].first) {
      p1[pos].second = max(p1[pos].second, p1[i].second);
    } else {
      p1[++pos] = p1[i];
    }
  }
  for (int i = 0; i <= pos; i++) {
    for (int j = p1[i].first; j <= p1[i].second; j++) {
      a[j] = a[p1[i].first];
    }
  }
  int flag = 1;
  for (int i = 0; i < n0; i++) {
    int f = 0;
    for (int j = p0[i].first + 1; j <= p0[i].second; j++) {
      if (a[j] != a[j - 1]) f = 1;
    }
    if (f == 0) flag = 0;
  }
  if (!flag)
    puts("NO");
  else {
    puts("YES");
    for (int i = 1; i <= n; i++) {
      printf("%d%c", a[i], i == n ? '\n' : ' ');
    }
  }
  return 0;
}
