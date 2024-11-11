#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, a, b, cnt = 0;
  cin >> n >> a >> b;
  if (a + b >= n) {
    cout << n - a;
  } else {
    cout << b + 1;
  }
}
int main() {
  solve();
  return 0;
}
