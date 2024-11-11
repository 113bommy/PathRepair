#include <bits/stdc++.h>
using namespace std;
const long long NMax = 500003;
const long long mod = 1000000007;
struct Edge {
  long long x, y, c;
};
Edge M[NMax];
long long last, x, y, ans, n, m, k;
long long c[NMax], pow2[NMax], father[NMax], rang[NMax];
long long root(int x) {
  while (x != father[x]) {
    x = father[x];
  }
  return x;
}
bool cmp(Edge x, Edge y) { return x.c < y.c; }
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; ++i) {
    cin >> c[i];
    father[i] = i;
    rang[i] = 1;
  }
  for (long long i = 1; i <= m; ++i) {
    cin >> x >> y;
    M[i].x = x;
    M[i].y = y;
    M[i].c = c[x] ^ c[y];
  }
  pow2[0] = 1;
  for (long long i = 1; i < NMax; ++i) {
    pow2[i] = pow2[i - 1] * 2 % mod;
  }
  sort(M + 1, M + 1 + m, cmp);
  last = 0;
  for (long long i = 1; i <= m; ++i) {
    long long j = i;
    long long nr = 0;
    long long comp = 0;
    set<int> s;
    map<int, int> mp;
    while (M[i].c == M[j].c) {
      if (mp.find(M[j].x) == mp.end()) {
        nr++;
        mp[M[j].x] = 1;
      }
      if (mp.find(M[j].y) == mp.end()) {
        nr++;
        mp[M[j].y] = 1;
      }
      int vf1 = root(M[j].x);
      int vf2 = root(M[j].y);
      s.insert(vf1);
      s.insert(vf2);
      if (vf1 == vf2) {
      } else {
        if (rang[vf1] > rang[vf2]) {
          father[vf2] = vf1;
          rang[vf1] += rang[vf2];
          s.erase(vf2);
        } else {
          father[vf1] = vf2;
          rang[vf2] += rang[vf1];
          s.erase(vf1);
        }
      }
      j++;
    }
    j--;
    ans += (pow2[n] * ((M[i].c % mod - last % mod + mod) % mod)) % mod;
    ans %= mod;
    last = M[i].c + 1;
    ans += (pow2[n - nr] * pow2[s.size()]) % mod;
    ans %= mod;
    for (int t = i; t <= j; ++t) {
      rang[M[t].x] = 1;
      rang[M[t].y] = 1;
      father[M[t].x] = M[t].x;
      father[M[t].y] = M[t].y;
    }
    i = j;
  }
  ans += (pow2[n] % mod * ((pow2[k] % mod - last % mod + mod) % mod)) % mod;
  cout << ans % mod << '\n';
}
