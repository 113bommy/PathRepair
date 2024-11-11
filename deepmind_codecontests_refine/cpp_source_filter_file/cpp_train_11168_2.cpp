#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 69;
int n;
int pre[MAXN];
int ans[MAXN];
int ask(int l, int r) {
  cout << "? " << l << ' ' << r << endl;
  int res;
  cin >> res;
  return res;
}
signed main() {
  cin >> n;
  for (int i = 2; i <= n; i++) pre[i] = ask(1, i);
  for (int i = n; i >= 3; i--) ans[i] = pre[i] - pre[i - 1];
  ans[1] = pre[n] - ask(2, n);
  ans[2] = pre[2] - ans[1];
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << ans << ' ';
}
