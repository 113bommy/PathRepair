#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9,
                  GOLD = ((1 + sqrt(5)) / 2);
template <class T>
int getbit(T s, int i) {
  return (s >> 1) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcount(s);
}
long long n;
map<pair<pair<long long, long long>, long long>, long long> vis;
vector<vector<long long>> stone;
map<pair<long long, long long>, vector<pair<long long, long long>>> Map;
void VarInput() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  stone.resize(n, vector<long long>(3, 0));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 3; j++) {
      cin >> stone[i][j];
    }
    for (long long x = 0; x < 3; x++) {
      for (long long y = x + 1; y < 3; y++) {
        long long z = stone[i][x], t = stone[i][y];
        if (z > t) swap(z, t);
        if (vis[make_pair(make_pair(z, t), i)]) continue;
        long long u = 0;
        if (x == 0 || y == 0) {
          if (x == 1 || y == 1)
            u = 2;
          else
            u = 1;
        }
        Map[make_pair(z, t)].push_back(make_pair(stone[i][u], i));
        vis[make_pair(make_pair(z, t), i)]++;
      }
    }
  }
}
void ProSolve() {
  vector<long long> ans;
  long long mx = 0;
  for (auto it = Map.begin(); it != Map.end(); it++) {
    pair<long long, long long> z = it->first;
    vector<pair<long long, long long>> v = it->second;
    sort(v.begin(), v.end(), greater<pair<long long, long long>>());
    if (v.size() == 1) {
      vector<long long> q(1, v[0].second);
      long long tmp = min(min(z.first, z.second), v[0].first);
      if (tmp > mx) {
        mx = tmp;
        ans = q;
      }
    } else {
      vector<long long> q(2, v[0].second);
      q[1] = v[1].second;
      long long tmp = min(min(z.first, z.second), v[0].first + v[1].first);
      if (tmp > mx) {
        mx = tmp;
        ans = q;
      }
    }
  }
  cout << ans.size() << '\n';
  for (long long i = 0; i < ans.size(); i++) cout << (ans[i] + 1) << " ";
}
int main() {
  VarInput();
  ProSolve();
  return 0;
}
