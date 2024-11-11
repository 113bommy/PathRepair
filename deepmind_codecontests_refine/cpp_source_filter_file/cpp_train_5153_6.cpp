#include <bits/stdc++.h>
using namespace std;
int gcd1(int a, int b) {
  if (a == 0) return b;
  return gcd1(b % a, a);
}
long long modx(long long base, long long ex) {
  long long ans = 1LL, val = base;
  while (ex > 0LL) {
    if (ex & 1LL) ans = (ans * val) % 1000000009LL;
    val = (val * val) % 1000000009LL;
    ex = ex >> 1LL;
  }
  return ans;
}
int n, k;
map<long long, long long> mp1, mp2;
map<long long, long long> cnt;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  long long a;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a % k == 0) {
      mp1[a] += cnt[a / k];
      mp2[a] += mp1[a / k];
    }
    cnt[a]++;
  }
  map<long long, long long>::iterator it;
  long long ans = 0;
  for (it = cnt.begin(); it != cnt.end(); it++) {
    if (it->first)
      ans += mp2[it->first];
    else {
      long long v = it->second;
      ans += (v * (v - 1) * (v - 2)) / 6;
    }
  }
  cout << ans << endl;
  return 0;
}
