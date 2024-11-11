#include <bits/stdc++.h>
using namespace std;
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
inline long long toLL(string s) {
  long long v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int> > v;
  vector<int> a(n);
  long long ans = 0;
  for (long long i = 0; i < (long long)(n); i++) {
    cin >> a[i];
    v.push_back({a[i], i});
  }
  sort((v).begin(), (v).end());
  ans = v.back().first - v[0].first;
  vector<int> diff(n - 1);
  for (long long i = 0; i < (long long)(n - 1); i++) {
    diff[i] = v[i + 1].first - v[i].first;
  }
  vector<long long> dp(n + 1, 0);
  for (long long i = (2); i < (n); ++i) {
    if (i + 3 <= n - 1) dp[i + 3] = max(dp[i + 3], dp[i] + diff[i]);
    dp[i + 1] = max(dp[i], dp[i + 1]);
  }
  ans -= dp[n];
  cout << ans << " ";
  long long res = dp[n];
  int cnt = 1;
  vector<int> flag;
  for (int i = n - 1; i >= 0; i--) {
    if (i - 3 >= 0 && dp[i] != 0 && res - dp[i - 3] == diff[i - 3]) {
      flag.push_back(i - 3);
      res = dp[i - 3];
      i = i - 3;
    }
  }
  cout << flag.size() + 1 << endl;
  reverse((flag).begin(), (flag).end());
  int ans2[n];
  int idx = 0;
  for (long long i = 0; i < (long long)(n); i++) {
    if (idx < flag.size() && i == flag[idx]) {
      ans2[v[i].second] = cnt;
      cnt++;
      idx++;
    } else {
      ans2[v[i].second] = cnt;
    }
  }
  for (long long i = 0; i < (long long)(n); i++) cout << ans2[i] << " ";
  cout << endl;
  return 0;
}
