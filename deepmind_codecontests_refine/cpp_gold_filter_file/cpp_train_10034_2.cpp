#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
int n;
vector<string> ans;
bool check(string s, int l, int r) {
  if (s[l] == '0') {
    if (r == l + 1) return true;
    return false;
  }
  int x = 0;
  for (int i(l); i < (r); i++) x = x * 10 + (s[i] - '0');
  return (x >= 0 && x < 256);
}
void func(string s) {
  int N = s.length();
  for (int i(1); i < (4); i++)
    for (int j(i + 1); j < (i + 4); j++)
      for (int k(j + 1); k < (j + 4); k++)
        if (N - k >= 1 && N - k <= 3) {
          if (check(s, 0, i) && check(s, i, j) && check(s, j, k) &&
              check(s, k, N)) {
            string t = s.substr(0, i) + "." + s.substr(i, j - i) + "." +
                       s.substr(j, k - j) + "." + s.substr(k, N - k);
            ans.push_back(t);
          }
        }
}
void dfs(int l, string s, int m, int p, int u) {
  if (p == l) {
    if (u == m) func(s);
    return;
  }
  int p2 = l - 1 - p;
  if (p2 < p) {
    if (u != m) return;
    char c = s[p2];
    dfs(l, s + c, m, p + 1, u);
  } else {
    char c;
    for (int i(0); i < (10); i++)
      if (m & (1 << i)) {
        c = '0' + i;
        dfs(l, s + c, m, p + 1, (u | (1 << i)));
      }
  }
}
int main() {
  cin >> n;
  int m = 0;
  for (int i(0); i < (n); i++) {
    int x;
    cin >> x;
    m |= (1 << x);
  }
  if (n <= 6)
    for (int i(4); i < (13); i++) dfs(i, "", m, 0, 0);
  cout << ans.size() << endl;
  for (int i(0); i < (ans.size()); i++) cout << ans[i] << endl;
  return 0;
}
