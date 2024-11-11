#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a < b)
    return a;
  else
    return b;
}
const int val = 110000;
int n, a[val], isBroken = 1, frstdiff, secdiff, frstdiffcnt, secdiffcnt,
               MissingIdx, mxdiff;
vector<int> ans;
set<int> st;
bool duplicate;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  if (n == 1) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int curdiff = a[1] - a[0];
  frstdiff = a[1] - a[0];
  st.insert(curdiff);
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) duplicate = 1;
    if (a[i] - a[i - 1] != curdiff) {
      if (st.find(a[i] - a[i - 1]) == st.end()) {
        st.insert(a[i] - a[i - 1]);
        isBroken++;
      }
    }
    curdiff = a[i] - a[i - 1];
    if (curdiff != frstdiff) secdiff = a[i] - a[i - 1];
    if (curdiff == frstdiff)
      frstdiffcnt++;
    else
      secdiffcnt++;
  }
  if (frstdiffcnt > secdiffcnt)
    mxdiff = frstdiff;
  else if (frstdiffcnt < secdiffcnt)
    mxdiff = secdiff;
  else {
    if (frstdiff > secdiff)
      mxdiff = secdiff;
    else
      mxdiff = frstdiff;
  }
  for (int i = 1; i < n; i++)
    if (a[i] - a[i - 1] != mxdiff) {
      MissingIdx = i;
      break;
    }
  if (frstdiffcnt > 1 && secdiffcnt > 1) isBroken = 3;
  if (isBroken > 2 || (duplicate && isBroken != 0)) {
    cout << 0;
    return 0;
  }
  if (isBroken == 0) {
    if (a[0] != a[n - 1]) ans.push_back(a[n - 1] + mxdiff);
    ans.push_back(a[0] - mxdiff);
  }
  if (n == 2) {
    if ((a[1] - a[0]) % 2 == 0 && a[1] - a[0] > 0)
      ans.push_back((a[0] + a[1]) / 2);
  }
  if (MissingIdx != 0)
    if ((a[MissingIdx] - mxdiff) - a[MissingIdx - 1] == mxdiff)
      ans.push_back(a[MissingIdx] - mxdiff);
  cout << ans.size() << "\n";
  sort(ans.begin(), ans.end());
  for (auto f : ans) cout << f << ' ';
  return 0;
}
