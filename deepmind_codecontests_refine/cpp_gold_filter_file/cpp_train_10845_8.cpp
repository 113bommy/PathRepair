#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
struct node {
  int a, b, val;
} s[maxn], p[maxn];
int cmp(node pp, node qq) { return pp.a < qq.a; }
int cmp1(node pp, node qq) {
  if (pp.val == qq.val) return pp.a > qq.a;
  return pp.val > qq.val;
}
int main() {
  ios::sync_with_stdio(false);
  int n, m, u, v;
  cin >> n >> m;
  int rs = 0, rt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> u >> v;
    if (v >= 0) {
      s[++rs].a = u;
      s[rs].b = v;
    } else {
      p[++rt].a = u;
      p[rt].b = v;
      p[rt].val = u + v;
    }
  }
  sort(s + 1, s + 1 + rs, cmp);
  int flag = 1;
  for (int i = 1; i <= rs; i++) {
    if (m >= s[i].a)
      m += s[i].b;
    else
      flag = 0;
  }
  if (!flag)
    cout << "NO" << endl;
  else {
    sort(p + 1, p + 1 + rt, cmp1);
    for (int i = 1; i <= rt; i++) {
      if (m >= p[i].a)
        m += p[i].b;
      else
        flag = 0;
    }
    if (!flag || m < 0)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
