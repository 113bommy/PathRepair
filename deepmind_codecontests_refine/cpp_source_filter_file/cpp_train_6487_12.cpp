#include <bits/stdc++.h>
using namespace std;
int n, m, k, num;
int father[3000];
int ans;
int f(int x) { return father[x] == x ? x : father[x] = f(father[x]); }
void u(int x, int y) {
  x = f(x);
  y = f(y);
  if (x != y) father[x] = y;
}
int main() {
  while (cin >> n >> m >> k) {
    num = 0, ans = 1;
    for (int i = 1; i <= n; ++i) father[i] = i;
    for (int i = 1; i + k - 1 <= n; ++i) {
      int x = i, y = i + k - 1;
      while (x <= y) {
        u(x, y);
        x++, y--;
      }
    }
    for (int i = 1; i <= n; ++i)
      if (father[i] == i) num++;
    for (int i = 0; i < num; ++i) ans *= m, ans %= 1000000007;
    cout << ans << endl;
  }
}
