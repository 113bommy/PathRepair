#include <bits/stdc++.h>
using namespace std;
inline long long getnum() {
  char c = getchar();
  long long num, sign = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = -1;
  for (num = 0; c >= '0' && c <= '9';) {
    c -= '0';
    num = num * 10 + c;
    c = getchar();
  }
  return num * sign;
}
vector<pair<long long, long long> > V;
int main() {
  long long x = getnum(), lim = LLONG_MAX;
  long long n = 1, l = 1, r = x, m;
  for (;;) {
    l = 1;
    long long cmp;
    while (l <= r) {
      m = (l + r) / 2;
      if (lim / (n * n) < m) {
        r = m;
        continue;
      }
      long long t = n - 1, sq = t * (t + 1) * (2 * t + 1) / 6;
      long long a1 = n * n * m;
      long long a2 = t * (t + 1) * (n + m) / 2;
      cmp = a1 - a2 + sq;
      if (cmp == x) {
        V.push_back(make_pair(n, m));
        break;
      }
      if (l == r) break;
      if (cmp < x)
        l = m + 1;
      else
        r = m;
    }
    n++;
    if (n > 2000000 || n >= m) break;
  }
  int xx = V.size() - 1;
  if (V[xx].first == V[xx].second)
    printf("%d\n", 2 * V.size() - 1);
  else
    printf("%d\n", 2 * V.size());
  for (int i = 0; i < V.size(); i++)
    printf("%I64d %I64d\n", V[i].first, V[i].second);
  for (int i = V.size() - 1; i >= 0; i--)
    if (V[i].first != V[i].second)
      printf("%I64d %I64d\n", V[i].second, V[i].first);
}
