#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string str;
  cin >> str;
  set<string> st;
  queue<string> que;
  st.insert(str), que.push(str);
  int sum = 0;
  while (!que.empty()) {
    string s = que.front();
    que.pop();
    for (int i = 0; i < s.size(); i++) {
      string temp = s;
      temp.erase(i, 1);
      if (!st.count(temp) && st.size() < m) {
        st.insert(temp);
        que.push(temp);
        sum += n - temp.size();
      }
    }
  }
  if (st.size() < m)
    cout << -1;
  else
    cout << sum;
}
