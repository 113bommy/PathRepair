#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int mod = (int)1e9 + 7;
const long double INF = (long double)(1e3);
const int N = 500005;
int n, m, ch, cs;
int S[N], H[N];
char s[N];
int solve(int x) {
  if (x + cs < ch) return 0;
  if (m >= 2 * n) return 1;
  if (x >= ch) return H[ch - 1] + 1 <= m;
  int t = 0, mn = (1 << 30), cur = 0;
  int lh = H[ch - 1], ls = S[ch - x - 1];
  for (int i = 0; i < n && cur < ch; ++i) {
    ++t;
    if (s[i] == 'S') ++x;
    if (s[i] == 'H') {
      ++cur;
      if (!x) {
        mn = min(mn, t + 2 * (max(lh, ls) - i));
        int b = 1;
        int j = i;
        while (b) {
          ++j;
          if (s[j] == 'S') --b;
          if (s[j] == 'H') ++b, ++cur;
        }
        t += 3 * (j - i);
        i = j;
      } else
        --x;
    }
  }
  mn = min(mn, t);
  return t <= m;
}
int main() {
  scanf("%d%d%s", &n, &m, s);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'H') H[ch++] = i;
    if (s[i] == 'S') S[cs++] = i;
  }
  int ans = -1;
  int l = 0;
  int r = n;
  while (l <= r) {
    int mid = ((l + r) >> 1);
    if (solve(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
