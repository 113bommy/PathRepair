#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e16;
const long long _inf = -1e16;
long long dx[] = {1, -1, 0, 0};
long long dy[] = {0, 0, 1, -1};
long long addmod(long long& a, long long b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
}
long long submod(long long& a, long long b) {
  a -= b;
  if (a < 0) a += 1000000007;
}
long long prea[5005];
long long preb[5005];
int main() {
  string s;
  long long l, i, hell, ans = 0, j;
  cin >> s;
  l = s.length();
  for (i = 0; i < l; i++) (s[i] == 'a') ? prea[i + 1] = 1 : preb[i + 1] = 1;
  for (i = 2; i <= l; i++) prea[i] += prea[i - 1], preb[i] += preb[i - 1];
  for (i = 0; i <= l; i++) {
    for (j = i; j <= l; j++) {
      hell = prea[i] + (preb[j] - preb[i]) + (prea[l - 1] - prea[j]);
      ans = max(ans, hell);
    }
  }
  cout << ans << endl;
  return 0;
}
