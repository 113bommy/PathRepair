#include <bits/stdc++.h>
using namespace std;
long long f[55], g[55], d[55], h[55];
long long a, b;
int k, x, n, m;
bool AC = false;
char toChar(int x) {
  if (x == 0)
    return 'A';
  else if (x == 1)
    return 'C';
  return 'Z';
}
void comp(int l, int x, int y, int &minn, int &maxx) {
  if (l == 1) {
    minn = maxx = 0;
    return;
  } else if (l == 2) {
    minn = maxx = (x == 0 && y == 1);
    return;
  }
  minn = maxx = 0;
  if (x == 0) {
    l -= 1;
    maxx = 1;
  }
  maxx += (l - 2) / 2;
  if ((l - 2) % 2 == 1 && y == 1) maxx++;
}
string create(int l, int x, int y, int t) {
  if (l == 1)
    return string(1, toChar(x));
  else if (l == 2)
    return string(1, toChar(x)) + string(1, toChar(y));
  string s = string(l, ' ');
  s[0] = toChar(x);
  s[l - 1] = toChar(y);
  for (int i = 1; i < l - 1; ++i)
    if (t == 0)
      s[i] = 'Z';
    else {
      if (s[i - 1] == 'A')
        s[i] = 'C', t--;
      else
        s[i] = 'A';
    }
  return s;
}
void check() {
  if (AC) return;
  string s1 = "", s2 = "";
  s1 = toChar(d[0]);
  if (n > 1) s1 += toChar(d[1]);
  s2 = toChar(d[2]);
  if (m > 1) s2 += toChar(d[3]);
  string ss = "";
  long long cnt = 0;
  h[1] = h[2] = 0;
  for (int i = 3; i <= k; ++i) {
    h[i] = h[i - 1] + h[i - 2];
    if (s1[s1.length() - 1] == 'A' && s2[0] == 'C') h[i]++;
    ss = s1 + s2;
    while (ss.length() > 2) ss.erase(1, 1);
    s1 = s2;
    s2 = ss;
  }
  long long X = x - h[k];
  int mina = 0, minb = 0, maxa = 0, maxb = 0;
  comp(n, d[0], d[1], mina, maxa);
  comp(m, d[2], d[3], minb, maxb);
  for (int i = mina; i <= maxa; ++i) {
    if (AC) break;
    for (int j = minb; j <= maxb; ++j)
      if (a * i + b * j == X) {
        cout << create(n, d[0], d[1], i) << endl;
        cout << create(m, d[2], d[3], j) << endl;
        AC = true;
        break;
      }
  }
}
void go(int i) {
  if (i >= 4) {
    if (n > 1 || d[0] == d[1])
      if (m > 1 || d[2] == d[3]) check();
  } else
    for (int j = 0; j < 3; ++j) {
      d[i] = j;
      go(i + 1);
    }
}
int main() {
  cin >> k >> x >> n >> m;
  f[1] = g[2] = 1;
  for (int i = 3; i <= k; ++i) {
    f[i] = f[i - 1] + f[i - 2];
    g[i] = g[i - 1] + g[i - 2];
  }
  a = f[k], b = g[k];
  go(0);
  if (!AC) cout << "Happy new year!" << endl;
  return 0;
}
