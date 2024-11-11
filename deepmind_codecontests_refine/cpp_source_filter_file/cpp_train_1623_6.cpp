#include <bits/stdc++.h>
using namespace std;
long long n, k;
string s;
long long cache[101][105][105];
long long dp(long long pos, long long tk, long long maxi) {
  if (pos == n) return maxi == k;
  if (maxi > k) maxi = k + 1;
  if (tk > k) tk = k + 1;
  if (cache[pos][tk][maxi] != -1) return cache[pos][tk][maxi];
  if (s[pos] != '?')
    return cache[pos][tk][maxi] = dp(pos + 1, (s[pos] == 'N') ? tk + 1 : 0,
                                     max(maxi, s[pos] == 'N' ? tk + 1 : 0));
  return cache[pos][tk][maxi] =
             max(dp(pos + 1, tk + 1, max(maxi, k + 1)), dp(pos + 1, 0, maxi));
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k >> s;
  memset(cache, -1, sizeof(cache));
  cout << ((dp(0, 0, 0) > 0) ? "YES" : "NO");
}
