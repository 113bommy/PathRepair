#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > s;
int n, m, tmp;
pair<int, int> a[200005];
int cnt[200005];
inline int read() {
  int ret = 0;
  char c = getchar();
  while ((c > '9') || (c < '0')) c = getchar();
  while ((c >= '0') && (c <= '9'))
    ret = (ret << 1) + (ret << 3) + c - '0', c = getchar();
  return ret;
}
int main() {
  m = read();
  n = read();
  for (int i = 1; i <= n; i++) cnt[read()]++;
  for (int i = 1; i <= m; i++)
    if (cnt[i]) s.insert(make_pair(i, cnt[i]));
  for (int i = 2; i < m; i++) {
    if (cnt[i]) s.erase(make_pair(i, cnt[i]));
    s.insert(make_pair(i, cnt[i] + 1));
    tmp = 0;
    int rest = m;
    while (rest) {
      set<pair<int, int> >::iterator p = s.upper_bound(make_pair(rest, n + 1));
      if (p == s.begin())
        break;
      else {
        p--;
        if (rest / (*p).first > (*p).second) {
          rest -= (*p).first * (*p).second;
          a[++tmp] = *p;
          s.erase(p);
        } else
          rest %= (*p).first;
      }
    }
    if (rest) {
      printf("%d", i);
      return 0;
    } else
      for (int j = 1; j <= tmp; j++) s.insert(a[tmp]);
    set<pair<int, int> >::iterator P = s.find(make_pair(i, cnt[i] + 1));
    s.erase(P);
    if (cnt[i]) s.insert(make_pair(i, cnt[i]));
  }
  puts("Greed is good");
}
