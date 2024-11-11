#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int MOD = 1e9 + 7;
const int INF = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  string s;
  cin >> n >> s >> m;
  if (m == 1) {
    int c = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        c++;
      }
    }
    cout << c;
    return 0;
  }
  vector<int> pad(n), pbd(n), pqd(n);
  for (int i = 0; i < n; i++) {
    if (i % 2 == 1 && s[i] != '?') {
      s[i] = 'a' + 'b' - s[i];
    }
    if (i) {
      pad[i] = pad[i - 1];
      pbd[i] = pbd[i - 1];
      pqd[i] = pqd[i - 1];
    }
    if (s[i] != 'b') {
      pad[i]++;
    }
    if (s[i] != 'a') {
      pbd[i]++;
    }
    if (s[i] == '?') {
      pqd[i]++;
    }
  }
  vector<int> okR(n), okL(n);
  for (int i = m - 1; i < n; i++) {
    int l = i - m + 1;
    if (l % 2 == 0) {
      int c = pad[i] - (l ? pad[l - 1] : 0);
      if (c == m) {
        okR[i] = 1;
        okL[i - m + 1] = 1;
      }
    } else {
      int c = pbd[i] - (l ? pbd[l - 1] : 0);
      if (c == m) {
        okR[i] = 1;
        okL[i - m + 1] = 1;
      }
    }
  }
  if (accumulate(okL.begin(), okL.end(), 0) == 0) {
    cout << 0;
    return 0;
  }
  vector<int> dpL(n);
  vector<int> mxL(n);
  for (int i = m - 1; i < n; i++) {
    if (okR[i]) {
      dpL[i] = 1;
      dpL[i] = max(dpL[i], (i - m >= 0 ? mxL[i - m] : 0) + 1);
    }
    mxL[i] = max(mxL[i - 1], dpL[i]);
  }
  vector<int> dp0(n, INF);
  vector<int> dp1(n, INF);
  dp0[0] = 0;
  dp1[0] = 0;
  for (int i = 1; i < n; i++) {
    if (mxL[i] == mxL[i - 1]) {
      dp0[i] = dp0[i - 1];
      dp1[i] = dp1[i - 1];
    } else {
      dp1[i] = dp0[i - 1];
    }
    if (okL[i]) {
      int cnt = (i - m >= 0 ? mxL[i - m] : 0) + 1;
      if (cnt == mxL[i]) {
        dp0[i] = min(dp0[i], (i - m >= 0 ? dp0[i - m] : 0) + pqd[i] -
                                 (i - m >= 0 ? pqd[i - m] : 0));
        dp1[i] = min(dp1[i], (i - m >= 0 ? dp1[i - m] : 0) + pqd[i] -
                                 (i - m >= 0 ? pqd[i - m] : 0));
      }
      if (cnt + 1 == mxL[i]) {
        dp1[i] = min(dp1[i], (i - m >= 0 ? dp0[i - m] : 0) + pqd[i] -
                                 (i - m >= 0 ? pqd[i - m] : 0));
      }
    }
  }
  cout << dp0[n - 1];
}
