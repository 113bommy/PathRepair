#include <bits/stdc++.h>
using namespace std;
const int Inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
int n, m;
int a[100005], b[100005];
int f[100005], fs, pos[100005];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= (n); ++i) scanf("%d", a + i);
  scanf("%d", &m);
  for (int i = 1; i <= (m); ++i) scanf("%d", b + i);
  sort(b + 1, b + m + 1);
  multiset<int> ms;
  for (int i = 1; i <= (m); ++i) ms.insert(b[i]);
  for (int i = 1; i <= (n); ++i) {
    if (~a[i]) {
      if (a[i] > f[fs])
        f[pos[i] = ++fs] = a[i];
      else {
        pos[i] = lower_bound(f + 1, f + fs + 1, a[i]) - f;
        f[pos[i]] = a[i];
      }
    } else {
      int pt = fs;
      for (int j = (m); (-1) > 0 ? j <= (1) : j >= (1); j += (-1)) {
        while (pt && f[pt] >= b[j]) --pt;
        if (pt == fs)
          f[++fs] = b[j];
        else
          f[pt + 1] = b[j];
      }
    }
  }
  int ln = 0, cur = Inf;
  for (int i = (n); (-1) > 0 ? i <= (1) : i >= (1); i += (-1)) {
    if (!~a[i]) {
      bool can = 1;
      for (int j = (i - 1); (-1) > 0 ? j <= (1) : j >= (1); j += (-1)) {
        if (~a[j] && a[j] < cur && pos[j] + ln == fs) {
          can = 0;
          break;
        }
      }
      if (can) {
        auto it = ms.lower_bound(cur);
        if (it != ms.begin()) {
          ++ln;
          --it;
          a[i] = cur = *it;
          ms.erase(it);
        }
      }
    } else if (a[i] < cur && pos[i] + ln == fs) {
      ++ln;
      cur = a[i];
    }
  }
  for (int i = 1; i <= (n); ++i)
    if (!~a[i]) {
      a[i] = *ms.begin();
      ms.erase(ms.begin());
    }
  for (int i = 1; i <= (n); ++i) printf("%d%c", a[i], " \n"[i == n]);
  return 0;
}
