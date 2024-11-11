#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
map<pair<long long, long long>, long long> F;
bool c(long long a, long long b) { return a <= b && a * 2 >= b; }
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  vector<bool> A(26, true);
  long long cnt = 26;
  long long li = 0;
  char c;
  string s;
  long long n;
  cin >> n;
  for (long long it = 0; it < n; ++it) {
    cin >> c >> s;
    if (c == '!') {
      if (cnt == 1) ++li;
      vector<long long> T(26);
      for (long long i = 0; i < s.size(); ++i) {
        T[s[i] - 'a'] = true;
      }
      for (long long i = 0; i < 26; ++i) {
        if (!T[i] && A[i]) {
          --cnt;
          A[i] = false;
        }
      }
    } else if (c == '.') {
      vector<long long> T(26);
      for (long long i = 0; i < s.size(); ++i) {
        T[s[i] - 'a'] = true;
      }
      for (long long i = 0; i < 26; ++i) {
        if (T[i] && A[i]) {
          --cnt;
          A[i] = false;
        }
      }
    } else {
      if (cnt == 1) {
        ++li;
      }
      if (A[s[0] - 'a']) {
        --cnt;
        A[s[0] - 'a'] = false;
      }
    }
  }
  if (cnt != 1) {
    ++li;
  }
  cout << li - 1 << endl;
  return 0;
}
