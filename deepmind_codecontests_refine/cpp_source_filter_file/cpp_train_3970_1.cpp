#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
bool check(pair<long long int, long long int> p1,
           pair<long long int, long long int> p2) {
  return p2.second > p1.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, k;
  cin >> n;
  string s[201], c[2];
  vector<string> ans;
  int j = 0;
  for (int i = 0; i < 2 * n - 2; i++) {
    cin >> s[i];
    if (s[i].size() == n - 1) {
      c[j++] = s[i];
    }
  }
  if (c[0].substr(1, n - 2) == c[1].substr(0, n - 2)) {
    ans.push_back(c[0] + c[1][n - 2]);
  }
  if (c[0].substr(0, n - 2) == c[1].substr(1, n - 2)) {
    ans.push_back(c[1] + c[0][0]);
  }
  string ans1 = "";
  bool ans2[2] = {1, 1};
  for (int i = 0; i < 2 * n - 2; i++) {
    int temp = s[i].size();
    if (s[i] == ans[0].substr(0, temp) ||
        s[i] == ans[0].substr(n - temp, temp)) {
    } else {
      ans2[0] = 0;
    }
    if (ans.size() > 1) {
      if (s[i] == ans[1].substr(0, temp) ||
          s[i] == ans[1].substr(n - temp, temp)) {
      } else {
        ans2[1] = 0;
      }
    }
  }
  string cmp;
  if (ans2[0]) {
    cmp = ans[0];
  } else if (ans.size() > 1) {
    cmp = ans[1];
  }
  string fina = "";
  map<string, bool> m;
  for (int i = 0; i < 2 * n - 2; i++) {
    int temp = s[i].size();
    if (s[i] == cmp.substr(0, temp) && !(m.count(s[i]) > 0)) {
      fina += "P";
      m[s[i]] = 1;
    } else {
      m[s[i]] = 1;
      fina += "S";
    }
  }
  cout << fina;
  return 0;
}
