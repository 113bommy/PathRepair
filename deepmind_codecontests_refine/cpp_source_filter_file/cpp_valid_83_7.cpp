#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
char s[N];
int n, f[N], ans, a[N];
unsigned int bas2[N], bas[N], base, base2, ha[N], Ha[N];
inline void init() {
  scanf("%d", &n);
  base = 31;
  base2 = 79;
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) a[i] = s[i] - 'a';
  bas[0] = 1;
  bas2[0] = 1;
  for (int i = 1; i <= n; i++)
    bas[i] = bas[i - 1] * base, bas2[i] = bas2[i - 1] * base2;
  for (int i = 1; i <= n; i++)
    ha[i] = ha[i - 1] * base + a[i], Ha[i] = Ha[i - 1] * base2 + a[i];
}
inline bool judge(int x, int y) {
  if (a[x] > a[y]) return 1;
  if (a[x] < a[y]) return 0;
  int l = 1, r = n - x + 1;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    unsigned int ha1, ha2, ha3, ha4;
    ha1 = ha[x + mid - 1] - ha[x - 1] * bas[mid];
    ha2 = ha[y + mid - 1] - ha[y - 1] * bas[mid];
    ha3 = Ha[x + mid - 1] - Ha[x - 1] * bas2[mid];
    ha4 = Ha[y + mid - 1] - Ha[y - 1] * bas2[mid];
    if (ha1 == ha2 && ha3 == ha4)
      l = mid;
    else
      r = mid - 1;
  }
  if (r == n - x + 1) {
    return 0;
  } else {
    if (a[x + l] > a[y + l])
      return l;
    else
      return 0;
  }
}
inline void solve() {
  ans = 0;
  for (int i = 1; i <= n; i++) {
    f[i] = n - i + 1;
    for (int j = 1; j < i; j++) {
      int t;
      if (t = judge(i, j)) {
        if (a[i] != a[j]) t--;
        f[i] = max(f[i], f[j] + n - i + 1 - t);
      }
    }
    ans = max(ans, f[i]);
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    init();
    solve();
  }
  return 0;
}
