#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int w[n];
  int d[m];
  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = 0; i < m; i++) cin >> d[i];
  set<int> prev;
  stack<int> st;
  for (int i = 0; i < m; i++)
    if (prev.count(d[i]) == 0) {
      prev.insert(d[i]);
      st.push(d[i]);
    }
  queue<int> xd;
  while (st.size() > 0) {
    xd.push(st.top());
    st.pop();
  }
  while (xd.size() > 0) {
    st.push(xd.front());
    xd.pop();
  }
  long long int ans = 0;
  for (int i = 0; i < m; i++) {
    stack<int> temp;
    int target = d[i];
    while (st.top() != target) {
      ans += w[st.top() - 1];
      temp.push(st.top());
      st.pop();
    }
    st.pop();
    while (temp.size() > 0) {
      st.push(temp.top());
      temp.pop();
    }
    st.push(target);
  }
  cout << ans;
}
