#include <bits/stdc++.h>
using namespace std;
bool func(int a, int m) {
  int sum = 0, cnt = 1;
  while (a) {
    int t = a % 10;
    if (t == 4 || t == 7) {
      t *= cnt;
      sum += t;
      cnt *= 10;
    }
    a /= 10;
  }
  if (sum == m) {
    return 1;
  }
  return 0;
}
void solve() {
  int a, b;
  cin >> a >> b;
  if (a < b) {
    cout << b;
  } else {
    while (a) {
      if (func(a, b)) {
        cout << a;
        return;
      } else {
        a++;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
