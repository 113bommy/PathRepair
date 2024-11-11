#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k1, k2, c1 = 0, c2 = 0, a, b;
  queue<int> q1, q2;
  cin >> n >> k1;
  while (k1--) {
    cin >> a;
    q1.push(a);
  }
  cin >> k2;
  while (k2--) {
    cin >> a;
    q2.push(a);
  }
  while ((!q1.empty()) && (!q2.empty())) {
    a = q1.front();
    q1.pop();
    b = q2.front();
    q2.pop();
    if (a > b) {
      q1.push(b);
      q1.push(a);
      c1++;
    } else {
      q2.push(a);
      q2.push(b);
      c2++;
    }
    if ((c1 > 2 * n) || (c2 > 2 * n)) {
      cout << -1 << endl;
      return 0;
    }
  }
  if (q1.empty())
    cout << c1 + c2 << " " << 2 << endl;
  else
    cout << c1 + c2 << " " << 1 << endl;
  return 0;
}
