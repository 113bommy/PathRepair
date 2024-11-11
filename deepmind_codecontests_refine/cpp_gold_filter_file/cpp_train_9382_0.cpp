#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  int a[n];
  stack<int> st;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (st.empty())
      st.push(a[i]);
    else if (abs(st.top() - a[i]) % 2 == 0)
      st.pop();
    else
      st.push(a[i]);
  }
  if (st.size() > 1)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
