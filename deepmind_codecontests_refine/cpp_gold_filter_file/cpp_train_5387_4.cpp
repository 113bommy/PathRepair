#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, mn = LLONG_MAX;
long long solve(string s, string tmp) {
  int ans = 0;
  for (int i = 0; i < 2; i++) {
    if (s[i] == tmp[i]) continue;
    int j = i;
    while (j < n && s[j] != tmp[i]) j++;
    if (j == n) return LLONG_MAX;
    while (j != i) {
      swap(s[j], s[j - 1]);
      j--;
      ans++;
    }
  }
  if (s[n - 1] == '0') {
    int i;
    bool f = 0;
    for (i = n - 1; i >= 2; i--) {
      if (s[i] != '0') {
        f = 1;
        break;
      }
    }
    if (f) ans += n - 1 - i;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string s;
  cin >> s;
  n = s.size();
  reverse(s.begin(), s.end());
  mn = min(mn, solve(s, "57"));
  mn = min(mn, solve(s, "52"));
  mn = min(mn, solve(s, "00"));
  mn = min(mn, solve(s, "05"));
  if (mn == LLONG_MAX)
    cout << "-1\n";
  else
    cout << mn << endl;
}
