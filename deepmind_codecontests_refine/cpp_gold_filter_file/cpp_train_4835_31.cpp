#include <bits/stdc++.h>
using namespace std;
void RI() {}
template <typename... T>
void RI(int& head, T&... tail) {
  scanf("%d", &head);
  RI(tail...);
}
inline int two(int x) { return 1 << x; }
inline int bit(int x, int i) { return (x >> i) & 1; }
int n, m, k, a[110][110];
int solve() {
  vector<int> vx, vy;
  for (int i = (1); i <= int(n); i++)
    for (int j = (1); j <= int(m); j++)
      if (a[i][j]) {
        vx.push_back(i);
        vy.push_back(j);
      }
  sort(begin(vx), end(vx));
  vx.erase(unique(begin(vx), end(vx)), vx.end());
  sort(begin(vy), end(vy));
  vy.erase(unique(begin(vy), end(vy)), vy.end());
  if (((int)(vx).size()) <= k) {
    int ret = 514;
    for (int msk = 0; msk < int(two(((int)(vx).size()))); msk++) {
      int now = 0;
      for (int j = (1); j <= int(m); j++) {
        int cnt = 0;
        for (int i = 0; i < int(((int)(vx).size())); i++)
          if (a[vx[i]][j] != bit(msk, i)) cnt++;
        now += min(cnt, n - cnt);
        if (now > k || now > ret) break;
      }
      if (now <= k) ret = min(ret, now);
    }
    return ret;
  } else if (((int)(vy).size()) <= k) {
    int ret = 514;
    for (int msk = 0; msk < int(two(((int)(vy).size()))); msk++) {
      int now = 0;
      for (int j = (1); j <= int(n); j++) {
        int cnt = 0;
        for (int i = 0; i < int(((int)(vy).size())); i++)
          if (a[j][vy[i]] != bit(msk, i)) cnt++;
        now += min(cnt, m - cnt);
        if (now > k || now > ret) break;
      }
      if (now <= k) ret = min(ret, now);
    }
    return ret;
  } else {
    return 514;
  }
}
int main() {
  RI(n, m, k);
  for (int i = (1); i <= int(n); i++)
    for (int j = (1); j <= int(m); j++) RI(a[i][j]);
  for (int i = (1); i <= int(n); i++)
    if (a[i][1])
      for (int j = (1); j <= int(m); j++) a[i][j] ^= 1;
  for (int i = (1); i <= int(m); i++)
    if (a[1][i])
      for (int j = (1); j <= int(n); j++) a[j][i] ^= 1;
  int ans = solve();
  k--;
  for (int i = (2); i <= int(n); i++)
    for (int j = (2); j <= int(m); j++) a[i][j] ^= 1;
  ans = min(ans, solve() + 1);
  k++;
  if (ans <= k)
    printf("%d\n", ans);
  else
    puts("-1");
  return 0;
}
