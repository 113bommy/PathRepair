#include <bits/stdc++.h>
using namespace std;
stringstream ss;
int a[1000010];
int main() {
  int n, t, x;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> t;
  for (int i = 1; i <= t; i++) cin >> x, a[x] *= -1;
  stack<int> st;
  for (int i = n; i > 0; i--) {
    if (a[i] < 0)
      st.push(-1 * a[i]);
    else {
      if (st.size() && st.top() == a[i])
        st.pop();
      else {
        st.push(a[i]);
        a[i] *= -1;
      }
    }
  }
  if (st.size())
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}
