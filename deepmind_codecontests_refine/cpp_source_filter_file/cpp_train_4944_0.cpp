#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int mod = INF + 9;
int dp[] = {0, 0, 2, 3, 322, 5, 53, 7, 7222, 7332};
void solve() {
  int n, k1, k2, x, y, f;
  cin >> n;
  queue<int> a, b;
  cin >> k1;
  while (k1--) {
    cin >> x;
    a.push(x);
  }
  cin >> k2;
  while (k2--) {
    cin >> x;
    b.push(x);
  }
  int cnt = 0;
  while (1) {
    if (a.empty()) {
      f = 2;
      break;
    }
    if (b.empty()) {
      f = 1;
      break;
    }
    cnt++;
    if (cnt > 100) {
      break;
    }
    x = a.front();
    a.pop();
    y = b.front();
    b.pop();
    if (x > y) {
      a.push(y);
      a.push(x);
    } else {
      b.push(x);
      b.push(y);
    }
  }
  if (cnt > 100) {
    cout << "-1";
    return;
  }
  cout << cnt << " " << f;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
