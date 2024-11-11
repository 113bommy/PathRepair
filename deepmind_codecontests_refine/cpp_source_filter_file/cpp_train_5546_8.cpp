#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, t, k, lu, ls;
  priority_queue<int> sign, unsignall;
  priority_queue<int, vector<int>, greater<int> > unsign;
  long double ans;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> n;
    ans = 1;
    if (n == 5) {
      for (j = 0; j < 5; j++) {
        cin >> k;
        ans *= k;
      }
      if (ans == 0 || ans == -0)
        cout << 0 << endl;
      else
        cout << ans << endl;
      continue;
    }
    while (!unsignall.empty()) unsignall.pop();
    while (!unsign.empty()) unsign.pop();
    while (!sign.empty()) sign.pop();
    for (j = 0; j < n; j++) {
      cin >> k;
      if (k < 0)
        unsign.push(k);
      else
        sign.push(k);
    }
    if (unsign.empty()) {
      for (k = 0; k < 5; k++) {
        ans *= sign.top();
        sign.pop();
      }
    } else if (sign.empty()) {
      while (!unsign.empty()) {
        unsignall.push(unsign.top());
        unsign.pop();
      }
      for (k = 0; k < 5; k++) {
        ans *= unsignall.top();
        unsignall.pop();
      }
    } else {
      ans *= sign.top();
      sign.pop();
      for (k = 0; k < 2; k++) {
        if (unsign.size() < 2) {
          ans *= sign.top();
          sign.pop();
          ans *= sign.top();
          sign.pop();
        } else if (sign.size() < 2) {
          ans *= unsign.top();
          unsign.pop();
          ans *= unsign.top();
          unsign.pop();
        } else {
          ls = sign.top();
          sign.pop();
          lu = unsign.top();
          unsign.pop();
          if (ls * sign.top() > lu * unsign.top()) {
            ans *= ls * sign.top();
            sign.pop();
            unsign.push(lu);
          } else {
            ans *= lu * unsign.top();
            unsign.pop();
            sign.push(ls);
          }
        }
      }
    }
    if (ans == 0 || ans == -0)
      cout << 0 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
