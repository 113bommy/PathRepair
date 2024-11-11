#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
int a[300005];
set<pair<int, int> > nex[300005];
int main() {
  int q = read();
  while (q--) {
    int n = read();
    a[n + 1] = a[n + 2] = 0;
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= n; ++i) nex[i].clear();
    long long ans = 0;
    for (int i = n - 1; i; --i) {
      if (a[i] == a[i + 1]) {
        swap(nex[i], nex[i + 2]);
        nex[i].insert(make_pair(a[i + 2], i + 2));
        ans = ans + nex[i].size();
        continue;
      }
      set<pair<int, int> >::iterator it =
          nex[i + 1].lower_bound(make_pair(a[i], 0));
      if (it == nex[i + 1].end() || (*it).first != a[i] || (*it).second > n)
        continue;
      int to = (*it).second;
      swap(nex[i], nex[to + 1]);
      nex[i].insert(make_pair(a[to + 1], to + 1));
      ans = ans + nex[i].size();
    }
    printf("%lld\n", ans);
  }
  return 0;
}
