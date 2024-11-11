#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int MAX = 1e5 + 9;
string s;
int main() {
  cin >> s;
  int cnt = 0, nb[100010];
  stack<int> st;
  int lft[100010], n = s.size();
  memset(lft, -1, sizeof lft);
  for (int i = 0; i < n; ++i) {
    nb[i] = cnt;
    if (s[i] == '[') ++cnt;
    if (s[i] == '[' || s[i] == '(')
      st.push(i);
    else if (!st.empty() && (s[i] == ']' && s[st.top()] == '[' ||
                             s[i] == ')' && s[st.top()] == '(')) {
      lft[i] = st.top();
      st.pop();
    } else {
      while (!st.empty()) st.pop();
    }
  }
  int mx = 0, l = 0, r = -1;
  for (int i = 0; i < n; ++i) {
    if (lft[i] == -1) continue;
    if (lft[i] && lft[lft[i] - 1] != -1) {
      lft[i] = lft[lft[i] - 1];
    }
    if (mx <= nb[i] - nb[lft[i]]) {
      mx = nb[i] - nb[lft[i]];
      r = i;
      l = lft[i];
    }
  }
  cout << mx << endl << s.substr(l, r - l + 1);
  return 0;
}
