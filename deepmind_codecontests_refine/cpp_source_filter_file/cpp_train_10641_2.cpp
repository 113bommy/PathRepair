#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int nn = n;
  vector<string> a;
  long long int s01 = 0, s10 = 0, s00 = 0, s11 = 0;
  set<string> ss01, ss10;
  while (nn--) {
    string vl;
    cin >> vl;
    if (vl[0] == '1' && vl.back() == '1') {
      s11 += 1;
    }
    if (vl[0] == '0' && vl.back() == '0') {
      s00 += 1;
    }
    if (vl[0] == '1' && vl.back() == '0') {
      s10 += 1;
      ss10.insert(vl);
    }
    if (vl[0] == '0' && vl.back() == '1') {
      s01 += 1;
      ss01.insert(vl);
    }
    a.push_back(vl);
  }
  if (s11 != 0 && s00 != 0 && s10 == 0 && s01 == 0) {
    cout << -1 << endl;
    return;
  }
  vector<long long int> res;
  if (s01 > s10 + 1) {
    for (long long int i = 0; i < a.size(); i++) {
      if (a[i][0] == '0' && a[i].back() == '1') {
        string ss = a[i];
        reverse(ss.begin(), ss.end());
        if (ss10.count(ss) == 0) {
          res.push_back(i);
        }
      }
    }
  } else if (s10 > s01 + 1) {
    for (long long int i = 0; i < a.size(); i++) {
      if (a[i][0] == '1' && a[i].back() == '0') {
        string ss = a[i];
        reverse(ss.begin(), ss.end());
        if (ss01.count(ss) == 0) {
          res.push_back(i);
        }
      }
    }
  }
  long long int mx = max(ss01.size(), ss10.size());
  long long int mn = min(ss01.size(), ss10.size());
  long long int ans = max(0ll, abs(mx - mn) / 2);
  cout << ans << endl;
  for (long long int i = 0; i < ans; i++) {
    cout << res[i] << " ";
  }
  cout << endl;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
