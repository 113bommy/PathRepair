#include <bits/stdc++.h>
using namespace std;
int n, cnt;
string a, like, b;
map<string, int> mp;
bool lk[100][100];
int ea, eb, ec;
int tri[10];
void init() {
  mp.clear();
  cnt = 0;
  memset(lk, 0, sizeof lk);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> like >> b;
    int ia, ib;
    if (mp.count(a) == 0)
      mp[a] = ia = cnt++;
    else
      ia = mp[a];
    if (mp.count(b) == 0)
      mp[b] = ib = cnt++;
    else
      ib = mp[b];
    lk[ia][ib] = true;
  }
  cin >> ea >> eb >> ec;
}
int abs(int x) {
  if (x < 0)
    return -x;
  else
    return x;
}
int get(int a, int b, int c) {
  int tmp = 0;
  for (int i = 0; i < tri[7]; i++) {
    int cc[4][8], ii = i;
    cc[0][0] = cc[1][0] = cc[2][0] = 0;
    for (int j = 0; j < 7; j++) {
      cc[ii % 3][++cc[ii % 3][0]] = j;
      ii /= 3;
    }
    if (cc[0][0] != a && cc[1][0] != b && cc[2][0] != c) continue;
    int ret = 0;
    for (int j = 0; j < 3; j++) {
      for (int k = 1; k <= cc[j][0]; k++)
        for (int r = 1; r <= cc[j][0]; r++)
          if (lk[cc[j][k]][cc[j][r]]) ret++;
    }
    tmp = max(tmp, ret);
  }
  return tmp;
}
void solve() {
  cnt = 7;
  tri[0] = 1;
  for (int i = 1; i <= 7; i++) tri[i] = tri[i - 1] * 3;
  int diff = 0x7fffffff, oth = 0;
  for (int i = 1; i < cnt; i++) {
    for (int j = 1; j + i < cnt; j++) {
      int k = cnt - i - j;
      int ex = ea / i, ey = eb / j, ez = ec / k;
      int ret = max(abs(ex - ey), max(abs(ex - ez), abs(ey - ez)));
      if (ret == diff) {
        oth = max(oth, get(i, j, k));
      }
      if (ret < diff) {
        diff = ret;
        oth = get(i, j, k);
      }
    }
  }
  cout << diff << " " << oth << endl;
}
int main() {
  init();
  solve();
  return 0;
}
