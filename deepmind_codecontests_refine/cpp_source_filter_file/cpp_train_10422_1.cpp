#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  x *= f;
}
int n;
int l[100010], r[100010];
long long ans;
bool cmp(int a, int b) { return a < b; }
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) {
    read(l[i]), read(r[i]);
    ans += l[i] + r[i] + 1;
  }
  sort(l + 1, l + n + 1, cmp);
  sort(r + 1, r + n + 1, cmp);
  for (int i = 1; i <= n; ++i) ans -= min(l[i], r[i]);
  printf("%d", ans);
  return 0;
}
