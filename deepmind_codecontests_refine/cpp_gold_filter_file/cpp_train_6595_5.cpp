#include <bits/stdc++.h>
using namespace std;
string str;
long long int debug = 0;
long long int recur(long long int a, long long int b, bool output) {
  if (a == 0 && b == 1) return 0;
  if (a == 1 && b == 0) return 0;
  if (a <= 0) return -(1ll << (long long int)(25));
  if (b <= 0) return -(1ll << (long long int)(25));
  if (a < b) {
    long long int t = b / a;
    long long int res = recur(a, b - a * t, output);
    if (output) str += string(t, 'B');
    return res + t;
  } else {
    long long int t = a / b;
    long long int res = recur(a - b * t, b, output);
    if (output) str += string(t, 'T');
    return res + t;
  }
}
int main() {
  long long int k, n, sum = 0;
  cin >> k >> n;
  pair<long long int, string> ans =
      make_pair((1ll << (long long int)(25)), "IMPOSSIBLE");
  for (long long int i = 0; i < ((long long int)(n + 1)); ++i) {
    if (recur(i, n, false) == k) {
      str = "";
      recur(i, n, true);
      str[0] = 'T';
      long long int cnt = 0;
      for (long long int j = 0; j < ((long long int)(k - 1)); ++j)
        if (str[j] == str[j + 1]) cnt++;
      ans = min(ans, make_pair(cnt, str));
    }
    if (recur(n, i, false) == k) {
      str = "";
      recur(n, i, true);
      str[0] = 'T';
      long long int cnt = 0;
      for (long long int j = 0; j < ((long long int)(k - 1)); ++j)
        if (str[j] == str[j + 1]) cnt++;
      ans = min(ans, make_pair(cnt, str));
    }
  }
  if (ans.first < n * 2) cout << ans.first << endl;
  cout << ans.second << endl;
}
