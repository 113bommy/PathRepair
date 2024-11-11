#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
using B = bitset<N>;
int n, kk, dep[N], fa[N];
B s[2], t[4], a, b;
vector<B> ss;
B query(B x, int y) {
  y = min(y, n - 1);
  static char c[N];
  cout << "? ";
  for (int i = 1; i <= n; i++) cout << (x[i] ? y : 0) << ' ';
  cout << endl;
  cin >> (c + 1);
  for (int i = 1; i <= n; i++)
    if (c[i] == '1') x[i] = 1;
  return x;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  while ((1 << kk) <= n) ++kk;
  s[0][1] = 1;
  for (int i = 1; i <= n; i++) a[i] = 1;
  ss.push_back(a);
  for (int i = kk - 1; i >= 0; --i) {
    int len = 1 << i;
    for (int j = 0; j < 4; j++) t[j] = query(s[j & 1], len - (j >> 1));
    s[0] |= s[1];
    s[1].reset();
    vector<B> ns;
    for (int j = 0; j < int(ss.size()); j++) {
      a = t[j & 1] & ss[j];
      b = t[(j & 1) + 2] & ss[j];
      s[1] |= a ^ b;
      ns.push_back(b);
      ns.push_back(ss[j] ^ b);
    }
    ss = ns;
  }
  for (int i = 0; i < int(ss.size()); i++)
    for (int j = 1; j <= n; j++)
      if (ss[i][j]) dep[j] = i;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < kk; j++) {
      a.reset();
      for (int k = 1; k <= n; k++) a[k] = (dep[k] % 3 == i && (k & (1 << j)));
      a = query(a, 1);
      for (int k = 1; k <= n; k++)
        fa[k] |= ((dep[k] + 2) % 3 == i && a[k]) << j;
    }
  cout << "!";
  for (int i = 2; i <= n; i++) cout << fa[i] << ' ' << i << endl;
  return 0;
}
