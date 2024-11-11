#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n;
string str;
long long get_s(long long h) { return (1 + h) * h / 2; }
int solve() {
  long long ans = 0, cnt = 0;
  stack<pair<long long, pair<long long, long long>>> st;
  for (int i = n - 1; i >= 0; i--) {
    if (str[i] == '1') {
      cnt++;
      while (!st.empty() && st.top().second.first < cnt) st.pop();
      long long sm = 0;
      if (st.empty()) {
        sm = 1LL * (n - (i + cnt)) * cnt;
      } else {
        sm = st.top().second.second - get_s(cnt) +
             (1LL * (st.top().first - i) * cnt);
      }
      st.push({i, {cnt, get_s(cnt) + sm}});
    } else {
      cnt = 0;
    }
    if (!st.empty()) {
      ans += st.top().second.second;
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cin >> str;
  cout << solve() << "\n";
  return 0;
}
