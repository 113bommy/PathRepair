#include <bits/stdc++.h>
using namespace std;
set<int> s[3];
int n, q;
int v[1000010][3], le[1000010], ri[1000010];
string st;
void init(int x, int l, int r) {
  le[x] = l;
  ri[x] = r;
  if (l == r) {
    if (st[l - 1] == 'R')
      v[x][0]++;
    else if (st[l - 1] == 'S')
      v[x][1]++;
    else if (st[l - 1] == 'P')
      v[x][2]++;
    return;
  }
  int m = (l + r) / 2;
  init(x * 2, l, m);
  init(x * 2 + 1, m + 1, r);
  for (int i = 0; i < 3; i++) v[x][i] = v[x * 2][i] + v[x * 2 + 1][i];
}
void update(int x, int p, int v0, int v1) {
  v[x][v0]--;
  v[x][v1]++;
  if (le[x] == ri[x]) return;
  int m = (le[x] + ri[x]) / 2;
  if (p <= m)
    update(x * 2, p, v0, v1);
  else
    update(x * 2 + 1, p, v0, v1);
}
int getleft(int x, int val) {
  if (le[x] == ri[x])
    return le[x];
  else if (v[x * 2][val] > 0)
    return getleft(x * 2, val);
  else
    return getleft(x * 2 + 1, val);
}
int getright(int x, int val) {
  if (le[x] == ri[x])
    return le[x];
  else if (v[x][val] - v[x * 2][val] == 0)
    return getright(x * 2, val);
  else
    return getright(x * 2 + 1, val);
}
int getnum(int x, int l, int r, int val) {
  if (le[x] >= l && ri[x] <= r) return v[x][val];
  int m = (le[x] + ri[x]) / 2;
  int ret = 0;
  if (l <= m) ret += getnum(x * 2, l, r, val);
  if (r > m) ret += getnum(x * 2 + 1, l, r, val);
  return ret;
}
void solve() {
  int ans = 0;
  for (int i = 0; i < 3; i++)
    if (v[1][i]) {
      int win = (i + 1) % 3, lose = (i) ? (i - 1) : 2;
      if (!v[1][lose])
        ans += v[1][i];
      else if (v[1][win]) {
        int blose = getleft(1, lose), elose = getright(1, lose);
        int bwin = getleft(1, win), ewin = getright(1, win);
        if (1 <= min(blose, ewin)) ans += getnum(1, 1, min(blose, ewin), i);
        if (max(bwin, elose) <= n) ans += getnum(1, max(bwin, elose), n, i);
        if (max(bwin, blose) <= min(ewin, elose))
          ans += getnum(1, max(bwin, blose), min(ewin, elose), i);
      }
    }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> q;
  cin >> st;
  init(1, 1, n);
  solve();
  while (q--) {
    int i;
    char c;
    cin >> i >> c;
    int v0, v1;
    if (st[i - 1] == 'R')
      v0 = 0;
    else if (st[i - 1] == 'S')
      v0 = 1;
    else if (st[i - 1] == 'P')
      v0 = 2;
    st[i - 1] = c;
    if (st[i - 1] == 'R')
      v1 = 0;
    else if (st[i - 1] == 'S')
      v1 = 1;
    else if (st[i - 1] == 'P')
      v1 = 2;
    update(1, i, v0, v1);
    solve();
  }
}
