#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  stack<int> st;
  int ans = 0;
  for (int i = 0; i < str.size(); i++) {
    if (st.size() && str[i] == st.top()) {
      st.pop();
      ans++;
    } else
      st.push(i);
  }
  if (ans & 1)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
