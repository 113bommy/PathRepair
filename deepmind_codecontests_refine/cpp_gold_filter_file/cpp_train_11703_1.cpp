#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const int nax = 2e5;
const long long mod = 1e9 + 7;
long long a, pre[4005];
string s;
map<long long, long long> mp;
long long ans = 0;
int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> a;
  cin >> s;
  long long sz = (long long)s.size();
  for (int i = 0; i < sz; i++) {
    pre[i + 1] = pre[i] + (s[i] - '0');
  }
  for (int i = 0; i < sz; i++) {
    for (int j = i + 1; j <= sz; j++) mp[pre[j] - pre[i]]++;
  }
  for (int i = 1; i * i <= a; i++) {
    if (a % i == 0) {
      long long temp = mp[i] * mp[a / i];
      if (a / i == i)
        ans += temp;
      else
        ans += (2 * temp);
    }
  }
  long long xp = (sz * (sz + 1));
  if (a == 0) ans = mp[0] * xp - (mp[0] * mp[0]);
  cout << ans << endl;
  return 0;
}
