#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
inline int sgn(const double &x) { return x < -eps ? -1 : x > eps; }
const int inf = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
int a[MAXN], ans[MAXN];
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  int st = n / 2;
  int d = 1;
  for (int i = 1; i <= n; ++i) {
    ans[i] = a[st];
    st += d;
    if (d < 0)
      d--;
    else
      d++;
    d = -d;
  }
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  puts("");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
