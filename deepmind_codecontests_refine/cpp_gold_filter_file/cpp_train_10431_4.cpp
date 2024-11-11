#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
int a[2002];
const long long Mod = 998244353;
long long d[2002][6001];
long long d__p(int pos, int cur) {
  long long &res = d[pos][cur + 2000];
  if (res != -1) return res;
  if (pos == n + 1) return res = cur > 0;
  res = 0;
  if (a[pos] == a[pos + 1])
    res = k * d__p(pos + 1, cur);
  else {
    res += (k - 2) * d__p(pos + 1, cur);
    res %= Mod;
    res += d__p(pos + 1, cur - 1);
    res %= Mod;
    res += d__p(pos + 1, cur + 1);
  }
  res %= Mod;
  return res;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[n + 1] = a[1];
  memset(d, -1, sizeof d);
  cout << d__p(1, 0);
  return 0;
}
