#include <bits/stdc++.h>
using namespace std;
int main() {
  stack<int> st;
  string s;
  int n, k;
  cin >> n >> k;
  cin >> s;
  vector<int> index;
  int i = 0;
  while (i < s.size()) {
    if (st.empty() || s[i] == '(')
      st.push(i++);
    else if (s[st.top()] == '(' && s[i] == ')') {
      index.push_back(st.top());
      index.push_back(i);
      st.pop();
      i++;
    } else
      st.push(i++);
  }
  vector<int> ans;
  for (int i = 0; i < k; i++) ans.push_back(index[i]);
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) cout << s[ans[i]];
  cout << "\n";
  return 0;
}
