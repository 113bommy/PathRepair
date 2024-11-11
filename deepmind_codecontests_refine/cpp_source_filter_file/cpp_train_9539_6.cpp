#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9 + 10;
struct P {
  int t, c;
} p[300010];
int n;
long long st, a, b, c, d;
int len;
long long sum1[300010], sum2[300010];
multiset<long long> s;
int main() {
  scanf("%d%I64d%I64d%I64d%I64d%I64d%d", &n, &a, &b, &c, &d, &st, &len);
  b = -b;
  d = -d;
  p[0].t = -1, p[0].c = -1;
  for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].t, &p[i].c);
  for (int i = 1; i <= n; i++) sum1[i] = sum1[i - 1] + (p[i].c == 0 ? b : a);
  for (int i = 1; i <= n; i++) sum2[i] = sum2[i - 1] + (p[i].c == 0 ? d : c);
  int r = 1;
  for (int i = 0; i <= n; i++) {
    int tt = p[i].t + 1;
    if (sum1[i] < 0) return 0 * puts("-1");
    if (i) s.erase(s.find(sum2[i]));
    while (r <= n && p[r].t < tt + len) {
      s.insert(sum2[r++]);
    }
    if (s.empty()) return 0 * printf("%d\n", tt);
    long long k = *s.begin();
    if (sum1[i] - sum2[i] + k + st >= 0) return 0 * printf("%d\n", tt);
  }
  return 0;
}
