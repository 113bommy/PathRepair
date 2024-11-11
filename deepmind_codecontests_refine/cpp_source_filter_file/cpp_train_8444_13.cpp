#include <bits/stdc++.h>
using namespace std;
int a, b, c, res;
void mo() {
  freopen("1091A.inp", "r", stdin);
  freopen("1091A.out", "w", stdout);
}
void nhap() { cin >> a >> b >> c; }
void xuli() {
  if (c - 1 <= b && c - 2 <= a) {
    res = max(res, c + c - 1 + c - 2);
  }
  if (b + 1 <= c && b - 1 <= a) {
    res = max(res, b + b + 1 + b - 1);
  }
  if (a + 1 <= b && a + 2 <= c) res = max(res, a + 1 + a + 1 + a + 2);
  cout << res;
}
int main() {
  nhap();
  xuli();
}
