#include <bits/stdc++.h>
using namespace std;
int n;
void dfs(string s, char mx) {
  if (s.size() == n) {
    cout << s << endl;
    return;
  }
  for (char c = 'a'; c <= mx + 1; c++) {
    string t = s;
    t += c;
    dfs(t, max(mx, c));
  }
}
int main() {
  cin >> n;
  dfs("", 'a');
  return 0;
}
