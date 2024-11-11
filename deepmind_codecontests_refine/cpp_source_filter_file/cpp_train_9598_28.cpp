#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, a, b, cnt = 0;
  cin >> n >> a >> b;
  if (a - b > 0) {
    cout << b + 1;
  } else {
    cout << n - a;
  }
}
int main() {
  solve();
  return 0;
}
