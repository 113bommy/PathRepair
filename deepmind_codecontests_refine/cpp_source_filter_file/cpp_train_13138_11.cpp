#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
namespace StrAlgo {
vector<int> Kmp(string s) {
  int n = (int(s.size()));
  vector<int> ans(n + 1);
  for (int i = 2; i <= n; i++) {
    ans[i] = ans[i - 1];
    while (ans[i] > 0 && s[ans[i]] != s[i - 1]) ans[i] = ans[ans[i]];
    ans[i] += s[ans[i]] == s[i - 1];
  }
  return ans;
}
vector<int> Z(string s) {
  int n = (int(s.size()));
  vector<int> ans(n + 1);
  int L = -1, R = -1;
  for (int i = 2; i <= n; i++) {
    if (i < R)
      ans[i] = min(ans[i - L], R - i);
    else
      L = i, R = i;
    while (i + ans[i] <= n && s[i - 1 + ans[i]] == s[ans[i]]) ans[i]++;
    if (i + ans[i] > R) L = i, R = i + ans[i];
  }
  return ans;
}
};  // namespace StrAlgo
void print(string s, int len) {
  if (len == 0)
    cout << "Just a legend\n";
  else
    cout << s.substr((int(s.size())) - len) << "\n";
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(), cout.tie();
  string s;
  cin >> s;
  int n = (int(s.size()));
  vector<int> z = StrAlgo::Z(s);
  int ln = 0;
  for (int i = 2; i <= n; i++) {
    ln = max(ln, z[i] - (i + z[i] == n + 1));
  }
  for (int i = 2; i <= n; i++) {
    if (i + z[i] == n + 1 && z[i] <= ln)
      return cout << s.substr(i - 1) << endl, 0;
  }
  return cout << "Just a legend\n", 0;
}
