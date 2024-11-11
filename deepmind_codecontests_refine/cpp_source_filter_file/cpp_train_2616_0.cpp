#include <bits/stdc++.h>
using namespace std;
int a[200005];
stack<int> stk;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    cout << "YES" << endl;
    return 0;
  }
  if (a[0] < a[1] || a[n - 2] > a[n - 1]) {
    cout << "NO" << endl;
    return 0;
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, a[i]);
    if ((!stk.empty()) && stk.top() == a[i]) {
      int prev = stk.top();
      stk.pop();
      if ((!stk.empty()) && stk.top() < prev) {
        cout << "NO" << endl;
        return 0;
      }
    } else
      stk.push(a[i]);
  }
  if ((stk.empty())) cout << "YES" << endl;
  if (stk.size() == 1) {
    if (stk.top() == mx)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
