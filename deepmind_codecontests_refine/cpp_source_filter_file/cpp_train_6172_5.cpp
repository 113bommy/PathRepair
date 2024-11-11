#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
const int N = 1e5 + 5;
long long n, a[7], b[N], cnt, ans = 1e9;
int num[N];
pair<long long, long long> x[6 * N];
int main() {
  for (int i = (1); i <= (6); ++i) a[i] = read();
  n = read();
  for (int i = (1); i <= (n); ++i) b[i] = read();
  for (int i = (1); i <= (6); ++i)
    for (int j = (1); j <= (n); ++j) x[++cnt] = {max(b[j] - a[i], 1ll), j};
  sort(x + 1, x + cnt + 1);
  int now = 0, j = 1;
  for (int i = (1); i <= (cnt); ++i) {
    if (!num[x[i].second]) ++now;
    ++num[x[i].second];
    if (num[x[j].second] > 1) --num[x[j].second], ++j;
    if (now == n) ans = min(ans, x[i].first - x[j].first);
  }
  printf("%lld\n", ans);
  return 0;
}
