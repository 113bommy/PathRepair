#include <bits/stdc++.h>
using namespace std;
int s1, s2;
char s[10];
string ans;
stack<int> st;
int main() {
  int n;
  cin >> n;
  while (scanf("%s", &s)) {
    while (!st.empty() && st.top() == 2) {
      ans += ">";
      st.pop();
    }
    if (!st.empty()) {
      int tmp = st.top();
      st.pop();
      if (tmp == 1) ans += ",";
      st.push(tmp + 1);
    }
    if (st.empty() && s1) {
      puts("Error occurred");
      return 0;
    }
    if (s[0] == 'p') {
      st.push(0);
      ans += "pair<";
    } else
      ans += "int";
    s1 = 1;
  }
  while (!st.empty() && st.top() == 2) {
    ans += ">";
    st.pop();
  }
  if (!st.empty()) {
    puts("Error occurred");
    return 0;
  }
  puts(ans.c_str());
  return 0;
}
