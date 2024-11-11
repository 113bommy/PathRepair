#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long MAX = 9223372036854775807;
const int N = 1e6 + 10;
int t[4 * N];
void build(int a[], int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] + t[v * 2 + 1];
  }
}
int query(int v, int tl, int tr, int l, int r) {
  if (l > r) return 1e9;
  if (l == tl && r == tr) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return min(query(v * 2, tl, tm, l, min(r, tm)),
             query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
int main() {
  ios_base::sync_with_stdio(0);
  ;
  string s;
  int n;
  cin >> n >> s;
  int tot = 0;
  int a[n + 1];
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(')
      tot++;
    else
      tot--;
    a[i] = tot;
  }
  build(a, 1, 0, n - 1);
  int ans = 0;
  if (n == 1) {
    cout << "0" << '\n';
    return 0;
    ;
  }
  if (tot == 2) {
    for (int i = 1; i < n - 1; ++i) {
      if (s[i] == ')') continue;
      int curr = query(1, 0, n - 1, 0, i - 1);
      if (curr < 0) continue;
      curr = query(1, 0, n - 1, i, n - 1);
      if (curr < 2) continue;
      ans++;
    }
    int curr = query(1, 0, n - 1, 0, n - 2);
    if (s[n - 1] == '(' and curr >= 0) ans++;
  } else if (tot == -2) {
    int curr = query(1, 0, n - 1, 1, n - 1);
    if (s[0] == ')' and curr >= -2) ans++;
    for (int i = 1; i <= n - 2; i++) {
      if (s[i] == '(') continue;
      curr = query(1, 0, n - 1, 0, i - 1);
      if (curr < 0) continue;
      curr = query(1, 0, n - 1, i, n - 1);
      if (curr < -2) continue;
      ans++;
    }
  }
  cout << ans << '\n';
  ;
  return 0;
}
