#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 4;
void generateParenthesis(int n, int open, int close, string s,
                         vector<string> &ans) {
  if (open == n && close == n) {
    ans.push_back(s);
    return;
  }
  if (ans.size() == n) {
    return;
  }
  if (open < n) {
    generateParenthesis(n, open + 1, close, s + "(", ans);
  }
  if (close < open) {
    generateParenthesis(n, open, close + 1, s + ")", ans);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    vector<string> ans;
    generateParenthesis(n, 0, 0, "", ans);
    for (int i = 0; i < n; i++) {
      cout << ans[i] << endl;
    }
  }
  return 0;
}
