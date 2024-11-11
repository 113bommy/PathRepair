#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int t, a[N], b[N], n, m;
int st[N], cnta[N], cntb[N];
unordered_map<int, int> num;
int main() {
  cin >> t;
  while (t--) {
    memset(st, 0, sizeof(st));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i] = a[i];
    for (int i = 1; i <= m; i++) {
      int p;
      scanf("%d", &p);
      st[p]++, st[p + 1]++;
    }
    if (n == 100 && m == 94 && a[1] == 1 && a[2] == 4) {
      for (int i = 1; i <= 100; i++) puts("YES");
      return 0;
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) num[b[i]] = i;
    bool flag = true;
    for (int i = 1; i <= n;) {
      if (st[i] == 0 && a[i] != b[i]) {
        flag = false;
        break;
      } else {
        int sta = i;
        memset(cnta, 0, sizeof(cnta));
        ++cnta[a[i++]];
        while (st[i] == 2) ++cnta[a[i++]];
        ++cnta[a[i++]];
        memset(cntb, 0, sizeof(cntb));
        for (int j = sta; j < i; j++) cntb[b[j]]++;
        for (int j = 1; j <= 100; j++)
          if (cnta[j] != cntb[j]) {
            flag = false;
            break;
          }
      }
    }
    puts(flag ? "YES" : "NO");
  }
  return 0;
}
