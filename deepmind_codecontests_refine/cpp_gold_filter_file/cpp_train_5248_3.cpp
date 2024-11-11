#include <bits/stdc++.h>
using namespace std;
int n, a[100001], c, k;
stack<int> st;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c;
    a[c] = 1;
    while (st.size() > 0 && st.top() < c) {
      a[c] = max(a[c], a[st.top()] + 1);
      st.pop();
    }
    if (st.size() == 0) a[c] = 0;
    st.push(c);
    k = max(k, a[c]);
  }
  cout << k;
  return 0;
}
