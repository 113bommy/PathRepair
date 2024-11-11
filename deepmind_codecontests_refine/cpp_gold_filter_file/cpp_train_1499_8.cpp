#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
map<string, int> m;
map<string, int> ans;
string s[1234];
int x[1234];
int main() {
  ios::sync_with_stdio(false);
  int n, MAX = -1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> x[i];
    m[s[i]] += x[i];
  }
  for (int i = 1; i <= n; i++) MAX = max(MAX, m[s[i]]);
  for (int i = 1; i <= n; i++) {
    ans[s[i]] += x[i];
    if (m[s[i]] == MAX && ans[s[i]] >= MAX) {
      cout << s[i] << endl;
      return 0;
    }
  }
  return 0;
}
