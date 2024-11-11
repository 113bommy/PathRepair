#include <bits/stdc++.h>
using namespace std;
int n, k, r1, r2;
string ans;
bool pytaj(int x, int y) {
  cout << 1 << " " << x << " " << y << '\n';
  fflush(stdout);
  cin >> ans;
  return ans[0] == 'T';
}
int znajdz(int l, int r) {
  if (r < l) return -1;
  while (l < r) {
    int d = (r - l + 1 - 2 + 3) / 4;
    int a = l + d;
    int b = r - d;
    if (pytaj(l, r))
      r = (l + r) / 2;
    else
      l = (l + r + 1) / 2;
  }
  return l;
}
bool sprawdz(int x) {
  if (x - 1 >= 1 && !pytaj(x, x - 1)) return 0;
  if (x + 1 <= n && !pytaj(x, x + 1)) return 0;
  return 1;
}
int32_t main() {
  cin >> n >> k;
  r1 = znajdz(1, n);
  r2 = znajdz(1, r1 - 1);
  if (r2 == -1 || !sprawdz(r2)) r2 = znajdz(r1 + 1, n);
  cout << 2 << " " << r1 << " " << r2 << '\n';
  fflush(stdout);
}
