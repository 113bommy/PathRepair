#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  int l[n + 1], r[n + 1];
  stack<int> st;
  for (int i = 1; i < n + 1; i++) {
    while (!st.empty() && a[st.top()] >= a[i]) st.pop();
    if (st.empty())
      l[i] = 0;
    else
      l[i] = st.top();
    st.push(i);
  }
  while (!st.empty()) st.pop();
  for (int i = n; i >= 1; i--) {
    while (!st.empty() && a[st.top()] >= a[i]) st.pop();
    if (st.empty())
      r[i] = n + 1;
    else
      r[i] = st.top();
    st.push(i);
  }
  vector<int> ans(n + 1, 0);
  vector<pair<int, int>> v1(n + 1);
  for (int i = 1; i < n + 1; i++) v1[i] = {a[i], r[i] - l[i] - 1};
  sort(v1.begin() + 1, v1.end(), greater<pair<int, int>>());
  int idx = 0;
  for (int i = 1; i < n + 1; i++) {
    if (idx == n) break;
    while (idx <= v1[i].second) {
      ans[idx] = max(ans[idx], (int)v1[i].first);
      idx++;
    }
  }
  for (int i = 1; i < n + 1; i++) cout << ans[i] << " ";
  cout << endl;
}
