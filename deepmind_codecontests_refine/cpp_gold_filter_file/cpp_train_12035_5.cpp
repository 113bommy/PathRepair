#include <bits/stdc++.h>
using namespace std;
map<long long, long long>::iterator itr1, itr2;
map<long long, map<long long, long long> > dp;
long long n, k, ans;
map<long long, long long> pre(long long sz) {
  if (dp.find(sz) != dp.end()) return dp[sz];
  map<long long, long long> ret;
  if (sz == 1) {
    ret[1] = 1;
  } else if (sz == 2) {
    ret[1] = 2;
  } else {
    long long L = (sz - 1) / 2, R = sz - L - 1;
    map<long long, long long> ml = pre(L), mr = pre(R);
    itr1 = ml.begin();
    itr2 = mr.begin();
    while (itr1 != ml.end() || itr2 != mr.end()) {
      if (itr1 == ml.end()) {
        ret.insert(*itr2), itr2++;
      } else if (itr2 == mr.end()) {
        ret.insert(*itr1), itr1++;
      } else if (itr1->first == itr2->first) {
        ret[itr1->first] = itr1->second + itr2->second;
        itr1++, itr2++;
      } else if (itr1->first < itr2->first) {
        ret.insert(*itr1), itr1++;
      } else
        ret.insert(*itr2), itr2++;
    }
    ret[min(L, R) + 1] += 1;
  }
  return dp[sz] = ret;
}
long long solve(long long sz, long long kth) {
  if (sz <= 2)
    return sz + 1 - kth;
  else if (kth == sz)
    return (sz + 1) / 2;
  long long val = 0, totL = 0, totR = 0, L = (sz - 1) / 2, R = sz - L - 1,
            chs = 1;
  map<long long, long long> v = dp[sz], vL = dp[L], vR = dp[R];
  for (itr1 = v.begin(); itr1 != v.end(); itr1++) {
    if (kth > itr1->second)
      kth -= itr1->second;
    else {
      val = itr1->first;
      break;
    }
  }
  for (itr1 = vR.begin(); itr1 != vR.end(); itr1++) {
    if (val > itr1->first)
      totR += itr1->second;
    else if (val == itr1->first)
      itr1->second >= kth ? chs = 2, totR += kth : kth -= itr1->second;
    else
      break;
  }
  if (chs == 2) return L + 1 + solve(R, totR);
  for (itr1 = vL.begin(); itr1 != vL.end(); itr1++) {
    if (val > itr1->first)
      totL += itr1->second;
    else if (val == itr1->first)
      itr1->second >= kth ? chs = 1, totL += kth : puts("WA");
    else
      break;
  }
  return solve(L, totL);
}
int main() {
  cin >> n >> k;
  if (k == 1)
    ans = 1;
  else if (k == 2)
    ans = n;
  else
    pre(n - 2), ans = solve(n - 2, n - 2 - (k - 2) + 1) + 1;
  cout << ans << endl;
  return 0;
}
