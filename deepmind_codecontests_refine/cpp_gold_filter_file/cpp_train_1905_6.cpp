#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, maxn = 1005;
int n, a[100005], b[maxn], pos[maxn], pre[maxn];
set<int> s;
set<int>::iterator l, r;
bool check(int n) {
  while (n) {
    if (n % 10 != 4 && n % 10 != 7) return 0;
    n /= 10;
  }
  return 1;
}
unsigned long long C(int n, int m) {
  if (m == 2) return (unsigned long long)n * (n - 1) / 2;
  if (m == 3) return (unsigned long long)n * (n - 1) * (n - 2) / 6;
  if (m == 4)
    return (unsigned long long)n * (n - 1) * (n - 2) / 6 * (n - 3) / 4;
}
int main() {
  while (~scanf("%d", &n)) {
    int m = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (check(a[i])) pos[++m] = i;
    }
    pos[m + 1] = n + 1;
    for (int i = 1; i <= m; i++) {
      pre[i] = 0;
      for (int j = i - 1; j >= 1; j--)
        if (a[pos[i]] == a[pos[j]]) {
          pre[i] = j;
          break;
        }
    }
    unsigned long long ans = C(n, 4) + 2ull * C(n, 3) + C(n, 2);
    for (int i = 2; i <= m; i++) {
      s.clear();
      s.insert(0);
      unsigned long long res = 0;
      for (int j = i; j <= m; j++) {
        if (pre[j] < i) {
          for (int k = pre[j]; k; k = pre[k]) {
            l = r = s.lower_bound(pos[k]);
            l--;
            if (r == s.end()) {
              res += (unsigned long long)(pos[k] - *l) * (pos[i - 1] - pos[k]) *
                     (pos[i] - pos[i - 1]);
              res += (unsigned long long)(pos[k] - *l) *
                     C(pos[i] - pos[i - 1] + 1, 2);
            } else
              res += (unsigned long long)(pos[k] - *l) * (*r - pos[k]) *
                     (pos[i] - pos[i - 1]);
            s.insert(pos[k]);
          }
        }
        ans -= res * (pos[j + 1] - pos[j]);
      }
    }
    printf("%I64u\n", ans);
  }
  return 0;
}
