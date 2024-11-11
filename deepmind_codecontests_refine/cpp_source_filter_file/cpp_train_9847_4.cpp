#include <bits/stdc++.h>
using namespace std;
int const lim = 1e3 + 3;
int const MLOG = 20, mod = 1e9 + 7;
int st[5003][1003], cnt[lim + 3][5];
map<string, int> indexes;
int no(int u) {
  if (u == 2)
    return 3;
  else
    return 2;
}
int get_xor(int u, int v) {
  if (u > 1 || v > 1) {
    if (u == v) return 0;
    if (u > 1 && v > 1) return 1;
    if (u > v) swap(u, v);
    if (u == 0)
      return v;
    else
      return no(v);
  }
  return u ^ v;
}
int get_and(int u, int v) {
  if (u > 1 || v > 1) {
    if (u == v) return v;
    if (u > 1 && v > 1) return 0;
    if (u > v) swap(u, v);
    if (u == 0)
      return 0;
    else
      return v;
  }
  return u & v;
}
int get_or(int u, int v) {
  if (u > 1 || v > 1) {
    if (u == v) return v;
    if (u > 1 && v > 1) return 1;
    if (u > v) swap(u, v);
    if (u == 0)
      return u;
    else
      return 1;
  }
  return u | v;
}
int get(int op, int u, int v) {
  if (op == 0) return get_xor(u, v);
  if (op == 1) return get_and(u, v);
  return get_or(u, v);
}
int main() {
  int n, m;
  cin >> n >> m;
  scanf("\n");
  for (int i = 0; i < m; i++) st[0][i] = 2;
  string nam;
  nam.push_back('?');
  indexes[nam] = 0;
  nam.clear();
  for (int i = 1; i <= n; i++) {
    string name;
    char x;
    while (scanf("%c", &x)) {
      if (x == ' ') break;
      name.push_back(x);
    }
    indexes[name] = i;
    scanf(":= ");
    string a, b;
    bool fa = false, fb = false;
    while (scanf("%c", &x)) {
      if (x == ' ' || x == '\n') break;
      if (x >= '0' && x <= '9') fa = true;
      a.push_back(x);
    }
    if (fa) {
      for (int j = 0; j < m; j++) st[i][j] = a[j] - '0';
      continue;
    }
    string ks;
    int op = 0;
    while (scanf("%c", &x)) {
      if (x == ' ') break;
      ks.push_back(x);
    }
    while (scanf("%c", &x)) {
      if (x == '\n') break;
      b.push_back(x);
    }
    if (ks == "OR")
      op = 2;
    else if (ks == "AND")
      op = 1;
    int ind1 = indexes[a], ind2 = indexes[b];
    for (int j = 0; j < m; j++) {
      st[i][j] = get(op, st[ind1][j], st[ind2][j]);
      cnt[j][st[i][j]]++;
    }
  }
  string mn, mx;
  for (int i = 0; i < m; i++) {
    if (cnt[i][2] >= cnt[i][3])
      mn.push_back('0');
    else
      mn.push_back('1');
  }
  for (int i = 0; i < m; i++) {
    if (cnt[i][2] > cnt[i][3])
      mx.push_back('1');
    else
      mx.push_back('0');
  }
  cout << mn << endl;
  cout << mx << endl;
}
