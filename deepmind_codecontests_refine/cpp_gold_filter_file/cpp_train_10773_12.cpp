#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long oo = 1e18 + 7, mod = 1e9 + 7;
const long long N = 1e5 + 5;
string s;
string s2;
vector<long long> vc;
long long val(long long l, long long r) {
  if (l > r) return 0;
  long long ans = 0, temp = 1;
  for (long long i = l; i <= r; i++) {
    if (s[i] == '+') {
      temp *= (s[i - 1] - '0');
      ans += temp;
      temp = 1;
    } else if (s[i] == '*') {
      temp *= (s[i - 1] - '0');
    }
  }
  temp *= (s[r] - '0');
  ans += temp;
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin >> s;
  vc.push_back(-1);
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] == '*') vc.push_back(i);
  }
  vc.push_back(s.length());
  long long maxi = val(0, s.length() - 1);
  for (long long i = 0; i < vc.size(); i++) {
    for (long long j = i + 1; j < vc.size(); j++) {
      long long itr1 = vc[i] + 1, itr2 = vc[j] - 1, pro = 1;
      itr1--;
      itr2++;
      while (itr1 >= 0 && s[itr1] != '+') {
        if (s[itr1] >= '1' && s[itr1] <= '9') pro *= (s[itr1] - '0');
        itr1--;
      }
      while (itr2 < s.length() && s[itr2] != '+') {
        if (s[itr2] >= '1' && s[itr2] <= '9') pro *= (s[itr2] - '0');
        itr2++;
      }
      maxi = max(maxi, val(0, itr1 - 1) + pro * val(vc[i] + 1, vc[j] - 1) +
                           val(itr2 + 1, s.length() - 1));
    }
  }
  cout << maxi;
}
