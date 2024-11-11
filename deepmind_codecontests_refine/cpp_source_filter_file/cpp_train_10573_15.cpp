#include <bits/stdc++.h>
using namespace std;
int ce(int a, int b) { return (a % b == 0 ? a / b : a / b + 1); }
void solve() {
  long long sum = 0;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  while (b && c && d) {
    b--;
    c--;
    d--;
    sum += 256;
  }
  while (a && b) {
    a--;
    b--;
    sum += 32;
  }
  cout << sum << endl;
}
int main() {
  int t = 1;
  while (t--) solve();
}
