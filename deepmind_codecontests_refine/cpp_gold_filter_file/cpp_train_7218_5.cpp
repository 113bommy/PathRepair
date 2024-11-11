#include <bits/stdc++.h>
using namespace std;
int n, f, f1;
string s, ans;
stack<int> state;
int main() {
  scanf("%d", &n);
  while (cin >> s) {
    if (f1) {
      puts("Error occurred");
      return 0;
    }
    if (s == "pair") {
      while (!state.empty() && state.top() == 2) {
        ans += ">";
        state.pop();
      }
      if (state.empty() && f) {
        puts("Error occurred");
        return 0;
      }
      if (!state.empty()) {
        int cnt = state.top();
        state.pop();
        if (cnt == 1) ans += ",";
        state.push(cnt + 1);
      }
      ans += "pair<";
      state.push(0);
    } else {
      while (!state.empty() && state.top() == 2) {
        ans += ">";
        state.pop();
      }
      if (state.empty() && f) {
        puts("Error occurred");
        return 0;
      }
      if (!state.empty()) {
        int cnt = state.top();
        state.pop();
        if (cnt == 1) ans += ",";
        state.push(cnt + 1);
      } else
        f1 = 1;
      ans += "int";
    }
    f = 1;
  }
  while (!state.empty() && state.top() == 2) {
    ans += ">";
    state.pop();
  }
  if (!state.empty()) {
    puts("Error occurred");
    return 0;
  }
  puts(ans.c_str());
  return 0;
}
