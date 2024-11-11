#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
vector<pair<int, int> > ret;
int base(int i, string &s) {
  int lasti = -1;
  if (s[i] == '(') {
    return base(i + 1, s);
  }
  for (int j = i; j < s.size(); j++) {
    if (s[j] == '(') {
      lasti = j;
    }
  }
  if (lasti != -1) {
    ret.push_back({i, lasti});
    reverse(s.begin() + i, s.begin() + lasti + 1);
    return base(i + 1, s);
  }
  return 0;
}
void solve(int i, int k, string &s) {
  if (k == 1) {
    base(i, s);
    return;
  }
  if (s[i] == '(') {
    for (int j = i + 1; j < s.size(); j++) {
      if (s[j] == ')') {
        reverse(s.begin() + i + 1, s.begin() + j + 1);
        if (i + 1 != j) {
          ret.push_back({i + 1, j});
        }
        solve(j + 1, k - 1, s);
        return;
      }
    }
  } else {
    for (int j = i + 1; j < s.size(); j++) {
      if (s[j] == '(') {
        reverse(s.begin() + i, s.begin() + j + 1);
        ret.push_back({i, j});
        solve(i, k, s);
        return;
      }
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    ret.clear();
    solve(0, k, s);
    cout << ret.size() << endl;
    for (pair<int, int> x : ret)
      cout << x.first + 1 << " " << x.second + 1 << endl;
  }
}
