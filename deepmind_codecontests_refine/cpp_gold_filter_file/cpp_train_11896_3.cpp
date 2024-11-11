#include <bits/stdc++.h>
using namespace std;
int n, d, m;
vector<int> a, b;
bool cmp(int x, int y) { return x > y; }
long long ans = 0;
int main() {
  scanf("%d %d %d", &n, &d, &m);
  a.clear();
  b.clear();
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    if (x <= m)
      a.push_back(x);
    else
      b.push_back(x);
  }
  sort(a.begin(), a.end(), cmp);
  sort(b.begin(), b.end(), cmp);
  if (!b.size()) {
    for (int i = 0; i < a.size(); i++) ans += a[i];
    return printf("%lld", ans), 0;
  }
  int now = 0, pos = 1;
  while (pos <= n) {
    ans += b[now++];
    pos += d + 1;
    if (now == b.size()) break;
  }
  pos -= d + 1;
  now--;
  pos = n - pos;
  for (int i = 0; i < min((int)a.size(), pos); i++) ans += a[i];
  if (pos >= a.size()) return printf("%lld", ans), 0;
  while (pos < a.size() && now > 0) {
    long long sum = 0;
    for (int i = pos; i < min((int)a.size(), pos + d + 1); i++) sum += a[i];
    if (sum > b[now]) {
      ans += sum - b[now];
      pos += d + 1;
      now--;
    } else
      break;
  }
  printf("%lld\n", ans);
}
