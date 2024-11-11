#include <bits/stdc++.h>
using namespace std;
const int oo = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
int arr[10010][30];
int solve(string s, string t) {
  for (int i = 0; i < (int)(26); ++i) arr[((long long)s.size())][i] = -1;
  for (int i = ((long long)s.size()) - 1; i >= 0; --i) {
    for (int k = 0; k < (int)(26); ++k) arr[i][k] = arr[i + 1][k];
    arr[i][s[i] - 'a'] = i;
  }
  int idx = 0;
  int ret = 1;
  for (int i = 0; i < (int)(((long long)t.size())); ++i) {
    if (arr[idx][t[i] - 'a'] != -1) {
      idx = arr[idx][t[i] - 'a'];
    } else {
      ++ret;
      idx = 0;
      if (arr[idx][t[i] - 'a'] == -1) return -1;
      idx = arr[idx][t[i] - 'a'];
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  cout << solve(s, t) << endl;
  return 0;
}
