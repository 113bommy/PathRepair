#include <bits/stdc++.h>
using namespace std;
long long inf = 1e18;
long long n, k;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  cin >> s;
  long long ans = inf;
  if (k > n) {
    cout << -1;
    return 0;
  }
  long long mn = inf;
  sort(s.begin(), s.end());
  s = "0" + s;
  for (long long i = 1; i <= n - k + 1; ++i) {
    string ss = "";
    ss.push_back(s[i]);
    long long ans = s[i] - 'a' + 1;
    long long lst = s[i] - 'a' + 1;
    for (long long j = i + 1; j <= n && ss.length() < k; ++j) {
      if (lst + 1 < s[j] - 'a') {
        ans += s[j] - 'a' + 1;
        lst = s[j] - 'a' + 1;
        ss.push_back(s[j]);
      }
    }
    if (ss.length() == k) {
      mn = min(mn, ans);
    }
  }
  mn = mn == inf ? -1 : mn;
  cout << mn;
  return 0;
}
