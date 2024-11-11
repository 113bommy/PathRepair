#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5, oo = 0x3f3f3f3f;
int nt[maxn];
pair<int, int> s[maxn];
int main(void) {
  int d, n, m;
  scanf("%d", &(d)), scanf("%d", &(n)), scanf("%d", &(m));
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    s[i] = pair<int, int>(x, y);
  }
  s[0] = pair<int, int>(d, 0);
  s[m + 1] = pair<int, int>(0, oo);
  m += 2;
  sort(s, s + m);
  stack<int> q;
  for (int i = m - 1; i >= 0; i--) {
    while (!q.empty() && s[i].second <= s[q.top()].second) q.pop();
    if (q.empty())
      nt[i] = -1;
    else
      nt[i] = q.top();
    q.push(i);
  }
  long long ans = 0;
  int now = n;
  int add = 0;
  for (int i = 0; i < m; i++) {
    if (now < 0) return puts("-1"), 0;
    if (nt[i] == -1) {
      add = d - s[i].first;
    } else
      add = s[nt[i]].first - s[i].first;
    if (add > n) add = n;
    if (add > now) {
      ans += (add - now) * 1ll * s[i].second;
      now = add;
    }
    now -= s[i + 1].first - s[i].first;
  }
  printf("%I64d\n", ans);
  return 0;
}
