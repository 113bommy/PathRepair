#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long double PI = 4 * atan(1);
long long l, n, x, lim;
stack<long long> second;
string st;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  second.push(1);
  lim = pow(2, 32) - 1;
  cin >> l;
  while (l--) {
    cin >> st;
    if (st == "add") {
      x += second.top();
      if (x > lim) {
        cout << "OVERFLOW!!!";
        return 0;
      }
    } else if (st == "for") {
      cin >> n;
      second.push(min(second.top() * n, lim + 1));
    } else {
      second.pop();
    }
  }
  if (x > lim) {
    cout << "OVERFLOW!!!";
    return 0;
  }
  cout << x;
  return 0;
}
