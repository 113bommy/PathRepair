#include <bits/stdc++.h>
#pragma warning(disable : 4786)
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int maxn = 1e5 + 5;
long long c[maxn], w[maxn];
int pay1[maxn], pay2[maxn];
struct node {
  long long cnt, val, id;
  bool operator<(const node& rhs) const {
    return cnt * val < rhs.cnt * rhs.val;
  }
};
set<node> s;
int main() {
  int n;
  long long m;
  memset(pay1, 0, sizeof(pay1));
  memset(pay2, 0, sizeof(pay2));
  scanf("%d %lld", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &c[i]);
    pay1[i] = c[i] / 100;
    c[i] %= 100;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &w[i]);
  }
  long long ans = 0;
  set<node>::iterator it;
  for (int i = 1; i <= n; i++) {
    node st = {100LL - c[i], w[i], i}, f;
    if (st.cnt == 100) continue;
    s.insert(st);
    if (m >= c[i]) {
      m -= c[i];
      pay2[i] = c[i];
    } else {
      m = m + 100 - c[i];
      pay2[i] = c[i];
      it = s.begin();
      f = *it;
      ans += f.cnt * f.val;
      ++pay1[f.id];
      pay2[f.id] = 0;
      s.erase(it);
    }
  }
  printf("%lld\n", ans);
  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", pay1[i], pay2[i]);
  }
  return 0;
}
