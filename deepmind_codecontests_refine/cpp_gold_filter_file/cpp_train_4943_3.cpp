#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, inp = "";
  while (cin >> s) inp += s;
  vector<int> ans;
  int i = 0;
  stack<int> st;
  for (; i < inp.size();) {
    if (inp[i] == ' ') continue;
    string cur = "";
    for (; i < inp.size() && inp[i] != '>'; i++) cur.push_back(inp[i]);
    cur.push_back('>');
    i++;
    if (cur == "<table>")
      st.push(0);
    else if (cur == "</table>") {
      ans.push_back(st.top());
      st.pop();
    } else if (cur == "<td>") {
      int v = st.top();
      st.pop();
      st.push(v + 1);
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
