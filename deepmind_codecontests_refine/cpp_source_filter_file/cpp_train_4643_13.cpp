#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  string s1 = s;
  long long int len = s.length();
  if (len == 1) {
    cout << s;
    return 0;
  }
  sort(s1.begin(), s1.end());
  stack<char> st;
  char dp[len];
  dp[len - 1] = 0;
  dp[len - 2] = s[len - 1];
  for (long long int i = len - 3; i >= 0; i--) {
    if (s[i + 1] > dp[i + 1])
      dp[i] = dp[i + 1];
    else
      dp[i] = s[i + 1];
  }
  string ans = "";
  long long int i = 0, index = 0;
  while (i != len) {
    if (s[i] == s1[index]) {
      ans += (s[i]);
      char temp = dp[i];
      while (!st.empty() && st.top() < temp) {
        char x = st.top();
        ans += (x);
        st.pop();
      }
      index++;
      while (s1[index] < dp[i] && index < len) index++;
    } else
      st.push(s[i]);
    i++;
  }
  while (!st.empty()) {
    char x = st.top();
    ans += x;
    st.pop();
  }
  cout << ans;
  return 0;
}
