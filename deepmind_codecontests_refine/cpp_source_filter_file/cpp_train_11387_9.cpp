#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const int MAXN = 1e5 + 10;
map<int, map<int, int>> mapCeption;
long long fact[MAXN], cnt[MAXN], m;
long long modExp(long long base, long long exp) {
  if (!exp)
    return 1LL;
  else {
    long long ans = modExp(base, exp / 2LL);
    ans = (ans * ans) % m;
    if (exp & 1LL) ans = (ans * base) % m;
    return ans;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int x;
  for (int i = (1); i < (n + 1); ++i) {
    cin >> x;
    ++mapCeption[x][0];
    ++mapCeption[x][i];
  }
  for (int i = (1); i < (n + 1); ++i) {
    cin >> x;
    ++mapCeption[x][0];
    ++mapCeption[x][i];
  }
  cin >> m;
  long long tmp;
  fact[0] = 1LL;
  for (int i = (1); i < (MAXN); ++i) {
    tmp = i;
    while (!(tmp & 1LL)) {
      ++cnt[i];
      tmp >>= 1;
    }
    cnt[i] += cnt[i - 1];
    fact[i] = (fact[i - 1] * tmp) % m;
  }
  long long ans = 1LL, twoCnt, tot;
  for (auto it = mapCeption.begin(); it != mapCeption.end(); ++it) {
    tot = it->second[0];
    it->second.erase(0);
    ans = (ans * fact[tot]);
    twoCnt = 0;
    for (auto it1 = it->second.begin(); it1 != it->second.end(); ++it1)
      twoCnt += (it1->second == 2);
    ans = (ans * modExp(2LL, cnt[tot] - twoCnt)) % m;
  }
  cout << ans << '\n';
  return 0;
}
