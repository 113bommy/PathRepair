#include <bits/stdc++.h>
using namespace std;
const int maxn = 200100;
int t[maxn], l[maxn], r[maxn];
int a[maxn];
int n, q, m;
int op1(int v, int l, int r) {
  if (v == l)
    return r;
  else
    return v - 1;
}
int op2(int v, int l, int r) { return l + r - v; }
int cal(int v) {
  for (int i = q; i >= 1; --i) {
    if (t[i] == 1) {
      if (v <= r[i] && v >= l[i]) v = op1(v, l[i], r[i]);
    } else {
      if (v <= r[i] && v >= l[i]) v = op2(v, l[i], r[i]);
    }
  }
  return v;
}
int main() {
  cin >> n >> q >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= q; ++i) {
    scanf("%d%d%d", &t[i], &l[i], &r[i]);
  }
  for (int i = 0; i < m; ++i) {
    int b;
    cin >> b;
    if (i == 0)
      cout << cal(b);
    else
      cout << " " << cal(b);
  }
}
