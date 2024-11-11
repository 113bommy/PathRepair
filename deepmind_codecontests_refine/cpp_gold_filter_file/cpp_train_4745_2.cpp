#include <bits/stdc++.h>
using namespace std;
int n, LT, RT;
const long long INF = 1e9;
bitset<3200> vis[3200];
bool OK_pow(int x, int y) {
  long long tmp = 1;
  for (int i = 0; i < y; i++) {
    tmp *= x;
    if (tmp > (long long)RT) {
      return true;
    }
  }
  return false;
}
int pow(int x, int y) {
  if (x == 1 || y == 0) return 1;
  int tmp = 1;
  while (y) {
    if (y & 1) tmp *= x;
    y >>= 1;
    x = x * x;
  }
  return tmp;
}
int main() {
  cin >> n >> LT >> RT;
  int d = RT - LT + 1;
  if (n == 1) {
    cout << d << endl;
    return 0;
  }
  if (n == 2) {
    cout << (long long)d * (d - 1) << endl;
    return 0;
  }
  int top;
  for (top = 2;; top++) {
    if (OK_pow(top, n - 1)) break;
  }
  long long ans = 0;
  vis[0][1] = true;
  for (int i = 1; i < top; i++) {
    for (int j = i + 1; j < top; j++) {
      vis[i][j] = vis[j % i][i];
      if (!vis[i][j]) continue;
      int aa = pow(i, n - 1);
      int bb = pow(j, n - 1);
      ans += 2 * max(0, RT / bb - (LT - 1) / aa);
    }
  }
  cout << ans << endl;
}
