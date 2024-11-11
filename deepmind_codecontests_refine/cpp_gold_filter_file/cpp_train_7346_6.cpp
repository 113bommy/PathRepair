#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
void solve() {
  vector<int> pre(1000, 0);
  int w;
  for (int i = 1;; i++) {
    int x = i * (i + 1) / 2;
    if (x > 10000) {
      w = i;
      break;
    }
    pre[i] = x;
  }
  int n;
  cin >> n;
  int y = lower_bound(pre.begin() + 1, pre.begin() + w, n) - pre.begin();
  if (pre[y] == n) {
    cout << y << '\n';
    for (int i = 1; i <= y; i++) {
      cout << i << " ";
    }
  } else {
    int x = n - pre[y - 1];
    y--;
    cout << y << '\n';
    cout << y + x << " ";
    for (int i = y - 1; i >= 1; i--) {
      cout << i << " ";
    }
  }
}
int main() {
  fast();
  solve();
  return 0;
}
