#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    int c = (b - a);
    ans += c / 5;
    c %= 5;
    ans += c / 2;
    c %= 2;
    ans += c;
    cout << ans << endl;
  }
}
