#include <bits/stdc++.h>
using namespace std;
int pr[30][100010], su[30][100010], ho[30][100010], qi[30][100010], qu[100010],
    q, l, x, y;
string s;
int que(int l, int r);
int quepr(int x, int y) {
  if (pr[y][x] == -1) pr[y][x] = que(qi[y][x], x);
  return pr[y][x];
}
int quesu(int x, int y) {
  if (su[y][x] == -1) su[y][x] = que(x, ho[y][x]);
  return su[y][x];
}
int que1(int x, int y) {
  if (qu[x] == -1) {
    qu[x] = que1(qi[y][x - 1], y) ^ quepr(x, y);
  }
  return qu[x];
}
int que(int l, int r) {
  int p = 0;
  for (int i = 0; i <= 26; i++) {
    if (ho[i][l] >= r) continue;
    p = p | (1 << (quepr(r, i) ^ quesu(l, i) ^ que1(ho[i][l], i) ^
                   que1(qi[i][r], i)));
  }
  for (int i = 0; i <= 27; i++)
    if ((p & (1 << i)) == 0) return i;
}
int main() {
  cin >> s;
  int l = s.length();
  for (int i = 0; i <= 26; i++) {
    int la = 0;
    for (int j = 0; j <= l + 1; j++) {
      qi[i][j] = la;
      if (s[j - 1] - 'a' + 1 == i || (j == l + 1 && i == 0)) la = j;
    }
  }
  for (int i = 0; i <= 26; i++) {
    int la = l + 1;
    for (int j = l + 1; j >= 0; j--) {
      ho[i][j] = la;
      if (s[j - 1] - 'a' + 1 == i || (j == 0 && i == 0)) la = j;
    }
  }
  for (int i = 0; i <= 26; i++)
    for (int j = 0; j <= l + 1; j++) pr[i][j] = su[i][j] = -1;
  for (int i = 1; i <= l; i++) qu[i] = -1;
  cin >> q;
  while (q--) {
    cin >> x >> y;
    if (que(x - 1, y + 1))
      cout << "Alice" << endl;
    else
      cout << "Bob" << endl;
  }
  return 0;
}
