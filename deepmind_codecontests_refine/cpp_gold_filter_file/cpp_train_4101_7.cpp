#include <bits/stdc++.h>
using namespace std;
long long solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> num(n, 0);
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    s += '.';
    long long curnum = 0;
    for (long long j = 0; j < s.length(); j++) {
      if (s[j] != '.') {
        curnum = curnum * 10 + (s[j] - '0');
      } else {
        num[i] = num[i] * (1 << 8);
        num[i] |= curnum;
        curnum = 0;
      }
    }
  }
  long long curnum = 0;
  for (long long i = 31; i >= 1; --i) {
    set<long long> st;
    curnum |= (1 << i);
    for (long long i = 0; i < n; i++) {
      st.insert(curnum & num[i]);
    }
    if (st.size() == k) {
      break;
    } else if (st.size() > k) {
      cout << "-1" << endl;
      return 0;
    }
    if (i == 1 && st.size() != k) {
      cout << "-1" << endl;
      return 0;
    }
  }
  vector<long long> ans(4);
  for (long long i = 0; i < 4; i++) {
    long long mask = (1 << 8) - 1;
    ans[i] = mask & curnum;
    curnum >>= 8;
  }
  for (long long i = 3; i >= 0; --i) {
    if (i == 0)
      cout << ans[i];
    else
      cout << ans[i] << ".";
  }
  return 0;
}
signed main() {
  long long t;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
