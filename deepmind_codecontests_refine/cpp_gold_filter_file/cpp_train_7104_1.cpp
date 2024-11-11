#include <bits/stdc++.h>
using namespace std;
void solve(int a, int b, int c) {
  if (!a && !b) {
    cout << string(c + 1, '1') << endl;
  } else if (!b && !c) {
    cout << string(a + 1, '0') << endl;
  } else {
    string res = string(c + 1, '1') + string(a + 1, '0');
    --b;
    while (b) {
      res += res.back() == '0' ? '1' : '0';
      b--;
    }
    cout << res << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    solve(a, b, c);
  }
  return 0;
}
