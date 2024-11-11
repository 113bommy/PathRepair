#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int read() {
  int w = 0, f = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') f = 1, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return f ? -w : w;
}
int x[N], a[N], n, m;
long long s[N];
int main() {
  n = read(), m = read();
  for (int i = 0; i < m; ++i) x[i] = read();
  int first, second;
  for (int i = 1; i < m; ++i) {
    first = x[i - 1], second = x[i];
    if (first > second) swap(first, second);
    if (first == second) continue;
    a[1] += second - first;
    if (second - first > 1) a[first + 1]--, a[second]++;
    a[first] += second - 1 - (second - first),
        a[first + 1] -= second - 1 - (second - first);
    a[second] += first - (second - first),
        a[second + 1] -= first - (second - first);
  }
  for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
  for (int i = 1; i <= n; ++i) printf("%lld ", s[i]);
  return 0;
}
