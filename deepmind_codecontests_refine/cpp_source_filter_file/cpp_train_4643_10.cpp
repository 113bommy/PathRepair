#include <bits/stdc++.h>
using namespace std;
int len;
char s[100005];
stack<int> st;
char ans[100005];
int las[100005];
int main() {
  cin >> s;
  len = strlen(s);
  if (len == 1) {
    cout << s << endl;
    return 0;
  }
  int now = 1;
  st.push(s[0]);
  las[len - 1] = s[len - 1] - 'a';
  for (int i = len - 2; i >= 0; i--) {
    las[i] = min(las[i - 1], s[i] - 'a');
  }
  int cnt = 0;
  while (1) {
    if (now == len) break;
    if (st.empty()) {
      st.push(s[now++]);
    } else if (las[now] < st.top() - 'a') {
      st.push(s[now++]);
    } else {
      ans[cnt++] = st.top();
      st.pop();
    }
  }
  while (!st.empty()) {
    ans[cnt++] = st.top();
    st.pop();
  }
  ans[cnt] = 0;
  cout << ans << endl;
  return 0;
}
