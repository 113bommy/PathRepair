#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a + c <= b)
    puts("0");
  else {
    int a2 = max(((a + b) >> 1) + 1, a);
    a += c;
    cout << a - a2 + 1 << endl;
  }
  return;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
