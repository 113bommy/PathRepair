#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int left[n + 2], right[n + 2], arr[n + 1];
  for (long long int i = 1; i <= n; i++) cin >> arr[i];
  stack<long long int> st;
  left[1] = 0;
  st.push(1);
  for (long long int i = 2; i <= n; i++) {
    while (!st.empty() && arr[i] < arr[st.top()]) st.pop();
    if (st.empty())
      left[i] = 0;
    else
      left[i] = st.top();
    st.push(i);
  }
  while (!st.empty()) st.pop();
  right[n] = n + 1;
  st.push(n);
  for (long long int i = n - 1; i >= 1; i--) {
    while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
    if (st.empty())
      right[i] = n + 1;
    else
      right[i] = st.top();
    st.push(i);
  }
  vector<vector<pair<long long int, long long int>>> arr1(n + 2);
  set<long long int> st1;
  vector<long long int> ans(n + 1, 0);
  for (long long int i = 1; i <= n; i++) {
    long long int dis = right[i] - left[i] - 1;
    arr1[0].push_back({arr[i], 0});
    arr1[dis + 1].push_back({arr[i], 1});
  }
  unordered_map<long long int, long long int> mp;
  for (long long int i = 0; i <= arr1[0].size(); i++) {
    mp[arr1[0][i].first]++;
    st1.insert(arr1[0][i].first);
  }
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 0; j < arr1[i].size(); j++) {
      mp[arr1[i][j].first]--;
      if (mp[arr1[i][j].first] == 0) st1.erase(arr1[i][j].first);
    }
    auto it = st1.end();
    it--;
    ans[i] = max(ans[i], *it);
  }
  for (long long int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
