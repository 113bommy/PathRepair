#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int nex[maxn];
pair<long long, char> p[maxn], t[maxn], pfirst, plast;
int n, m;
void get_nex() {
  int j = 1;
  nex[2] = 1;
  for (int i = 3; i < m; i++) {
    while (j > 1 && p[j + 1] != p[i]) j = nex[j];
    if (p[j + 1] == p[i]) j++;
    nex[j] = j;
  }
}
long long kmp() {
  int len = m - 2, j = 1;
  long long ans = 0;
  for (int i = 2; i < n; i++) {
    while (j > 1 && p[j + 1] != t[i]) j = nex[j];
    if (p[j + 1] == t[i]) j++;
    if (j - 1 == len) {
      if (t[i + 1].first >= plast.first && t[i + 1].second == plast.second &&
          t[i - len].first >= pfirst.first &&
          t[i - len].second == pfirst.second)
        ans++;
    }
  }
  return ans;
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    int mt = 0, nt = 0;
    memset(p, 0, sizeof(p));
    memset(t, 0, sizeof(t));
    for (int i = 1; i <= n; i++) {
      int x;
      char ch;
      scanf("%d-%c", &x, &ch);
      if (ch == t[nt].second)
        t[nt].first += x;
      else
        t[++nt] = make_pair(x, ch);
    }
    for (int i = 1; i <= m; i++) {
      int x;
      char ch;
      scanf("%d-%c", &x, &ch);
      if (ch == p[mt].second)
        p[mt].first += x;
      else
        p[++mt] = make_pair(x, ch);
    }
    m = mt, n = nt;
    long long ans = 0;
    if (m == 1) {
      for (int i = 1; i <= n; i++) {
        if (p[1].second == t[i].second && p[1].first <= t[i].first)
          ans += (t[i].first - p[1].first + 1);
      }
    } else if (m == 2) {
      for (int i = 1; i < n; i++) {
        if (p[1].second == t[i].second && p[1].first <= t[i].first &&
            p[2].second == t[i + 1].second && p[2].first <= t[i + 1].first)
          ans++;
      }
    } else {
      pfirst = p[1];
      p[1] = make_pair(0, 0);
      plast = p[m];
      p[m] = make_pair(0, 0);
      get_nex();
      ans = kmp();
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
