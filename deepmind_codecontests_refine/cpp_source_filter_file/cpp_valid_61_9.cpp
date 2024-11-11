#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &i : v) cin >> i;
  return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &v) {
  for (auto &i : v) cout << i << " ";
  return out;
}
void solve() {
  long long int i, j, n, a, b, c, d = -1, m, k = -1, sum = 0, ans = 0, cnt = 0,
                                  r = 0, e = 0, x = 0, y = 0;
  string str, s1 = "", om, s;
  map<long long int, long long int> mp, mp1;
  set<long long int> st;
  cin >> n >> s;
  for (i = 0; i < n; i++) {
    if (s[i] == 'B') {
      k = i;
      break;
    }
    if (s[i] == 'R') {
      d = i;
      break;
    }
  }
  for (i = 0; i < n; i++) {
    if (s[i] == '?') {
      if (k != -1) {
        if (i % 2 == k % 2)
          s1 += 'B';
        else
          s1 += 'R';
      } else {
        if (i % 2 == d % 2)
          s1 += 'B';
        else
          s1 += 'R';
      }
    } else
      s1 += s[i];
  }
  for (i = 0; i < n - 1; i++) {
    if (s[i] == '?') {
      if (s1[i + 1] == s1[i]) {
        if (s1[i + 1] == 'R')
          s1[i] = 'B';
        else
          s1[i] = 'R';
      }
    }
  }
  for (i = 1; i <= n - 1; i++) {
    if (s[i] == '?') {
      if (s1[i - 1] == s1[i]) {
        if (s1[i - 1] == 'R')
          s1[i] = 'B';
        else
          s1[i] = 'R';
      }
    }
  }
  cout << s1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
