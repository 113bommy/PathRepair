#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int n, k, fa[N], dep[N];
vector<bitset<N> > v;
bitset<N> s[2], t[4];
bitset<N> query(bitset<N> s, int t) {
  t = min(t, n - 1);
  static char ans[N];
  bitset<N> ret;
  cout << "?";
  for (int i = 1; i <= n; i++) cout << " " << (s[i] ? t : 0);
  cout << endl;
  scanf("%s", ans + 1);
  for (int i = 1; i <= n; i++)
    if (ans[i] == '1') s[i] = 1;
  return s;
}
int main() {
  n = gi(), k = 1;
  while ((1 << k) < n) ++k;
  s[0][1] = 1;
  bitset<N> tmp;
  for (int i = 1; i <= n; i++) tmp[i] = 1;
  v.push_back(tmp);
  for (int i = k - 1; ~i; i--) {
    for (int j = 0; j < 4; j++) t[j] = query(s[j & 1], (1 << i) - (j >> 1));
    s[0] |= s[1];
    s[1].reset();
    vector<bitset<N> > vv;
    for (int j = 0; j < int(v.size()); j++) {
      bitset<N> a = t[j & 1] & v[j], b = t[(j & 1) + 2] & v[j];
      s[1] |= a ^ b;
      vv.push_back(b), vv.push_back(v[j] ^ b);
    }
    swap(v, vv);
  }
  for (int i = 0; i < int(v.size()); i++)
    for (int j = 1; j <= n; j++)
      if (v[i][j]) dep[j] = i;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < k; j++) {
      tmp.reset();
      for (int l = 1; l <= n; l++) tmp[l] = (dep[l] == i && (l >> j & 1));
      tmp = query(tmp, 1);
      for (int l = 1; l <= n; l++)
        fa[l] |= ((dep[l] + 2) % 3 == i && tmp[l]) << j;
    }
  cout << "!\n";
  for (int i = 2; i <= n; i++) cout << fa[i] << ' ' << i << '\n';
  return 0;
}
