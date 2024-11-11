#include <bits/stdc++.h>
using namespace std;
int sum, b[501], c[501], d[501], a[501];
int main() {
  stack<int> s1, s2;
  int n, day, q, con = 0, l;
  cin >> n >> day;
  for (int i = 0; i != n; i++) {
    cin >> q;
    b[i + 1] = q;
    a[i + 1] = q;
  }
  for (int i = 0; i != day; i++) {
    cin >> q;
    if (b[q] != 0) {
      d[con] = q;
      con++;
      b[q] = 0;
      c[i] = q;
    }
    c[i] = q;
  }
  for (int i = con - 1; i >= 0; i--) s1.push(d[i]);
  for (int i = 0; i != day; i++) {
    while (!s1.empty()) {
      if (s1.top() == c[i]) {
        l = s1.top();
        s1.pop();
        break;
      } else {
        sum += a[s1.top()];
        s2.push(s1.top());
        s1.pop();
      }
    }
    while (!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
    s1.push(l);
  }
  cout << sum;
  return 0;
}
