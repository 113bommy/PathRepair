#include <bits/stdc++.h>
using namespace std;
queue<int> q1;
queue<int> q2;
int main() {
  int n, k1, k2, a, ans = 0;
  cin >> n;
  cin >> k1;
  for (int i = 0; i < k1; i++) {
    cin >> a;
    q1.push(a);
  }
  cin >> k2;
  for (int i = 0; i < k2; i++) {
    cin >> a;
    q2.push(a);
  }
  while (!q1.empty() && !q2.empty()) {
    if (ans > 200) {
      cout << "-1";
      break;
    }
    if (q1.front() > q2.front()) {
      int x = q1.front();
      int y = q2.front();
      q2.pop();
      q1.pop();
      q1.push(y);
      q1.push(x);
      ans++;
    } else {
      int x = q1.front();
      int y = q2.front();
      q2.pop();
      q1.pop();
      q2.push(x);
      q2.push(y);
      ans++;
    }
  }
  if (q1.size() == 0) {
    cout << ans << " " << 2;
  } else if (q2.size() == 0)
    cout << ans << " " << 1;
  return 0;
}
