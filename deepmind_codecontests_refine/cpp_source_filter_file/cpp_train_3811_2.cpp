#include <bits/stdc++.h>
using namespace std;
struct binary_indexed_tree {
  int n;
  vector<int> a;
  void init(int t) { n = t + 10, a.clear(), a.resize(n); }
  void add(int p, int t) {
    for (int i = p; i < n; i += i & -i) a[i] += t;
  }
  int sum(int p) {
    int ret = 0;
    if (p <= 0) return 0;
    for (int i = p; i; i -= i & -i) ret += a[i];
    return ret;
  }
} tree[11][11][4];
int get_type(char c) {
  if (c == 'A')
    return 0;
  else if (c == 'T')
    return 1;
  else if (c == 'G')
    return 2;
  else if (c == 'C')
    return 3;
  return -1;
}
int n, c, l, r, len, oper, ans;
string s, t;
int main() {
  cin >> s;
  len = s.length();
  for (int i = 0; i <= 10; ++i)
    for (int j = 0; j <= 10; ++j)
      for (int k = 0; k < 4; ++k) tree[i][j][k].init(len);
  for (int i = 0; i < len; ++i)
    for (int j = 1; j <= 10; ++j)
      tree[j][(i + 1) % j][get_type(s[i])].add(i + 1, 1);
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &oper);
    if (oper == 1) {
      scanf("%d", &c);
      cin >> t;
      for (int i = 1; i <= 10; ++i) {
        tree[i][c % i][get_type(s[c])].add(c, -1);
        tree[i][c % i][get_type(t[0])].add(c, 1);
      }
      s[c] = t[0];
    } else {
      scanf("%d%d", &l, &r);
      cin >> t;
      len = t.length(), ans = 0;
      for (int i = 0; i < len; ++i) {
        ans += tree[len][(l + i) % len][get_type(t[i])].sum(r) -
               tree[len][(l + i) % len][get_type(t[i])].sum(l - 1);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
