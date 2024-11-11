#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  int n, l, a;
  cin >> n >> l >> a;
  int ans = 0, cur = 0;
  while (n--) {
    int st, ed;
    cin >> st >> ed;
    if (cur != st) ans += (st - cur) / a;
    cur = ed + 1;
  }
  ans += (l - cur) / a;
  cout << ans << endl;
  return 0;
}
