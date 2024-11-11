#include <bits/stdc++.h>
#pragma optimization_level 3
using namespace std;
long double TL = 1.0;
bool is_tl = 0;
long long CALLS = 0;
inline bool IS() {
  if (++CALLS == 1000) {
    CALLS = 0;
    is_tl |= clock() > (TL - 0.1) * CLOCKS_PER_SEC;
  }
  return is_tl;
}
template <typename T>
inline void amin(T &a, T b) {
  if (a > b) a = b;
}
template <typename T>
inline void amax(T &a, T b) {
  if (a < b) a = b;
}
template <typename T>
inline void print(T a) {
  for (auto U : a) cout << U << ' ';
  cout << '\n';
}
const long long N = 1e5 + 7, NS = 1e3 + 7, lg = 18, sq = 550, inf = 1e9 + 7,
                mod = 1e9 + 7, SM = 1e2 + 7;
const long double eps = 1e-9;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<long long> v[N], r[N];
long long used[N], used2[N], mt[N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, e;
  cin >> n >> e;
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    a--, b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for (long long i = 0; i < n; i++) {
    long long c1 = 0, c2 = 0;
    for (auto u : v[i]) {
      if (used[u] == 1) c1++;
      if (used[u] == 2) c2++;
    }
    if (c1 > c2)
      used[i] = 2;
    else
      used[i] = 1;
  }
  vector<long long> teams;
  for (long long i = 0; i < n; i++) {
    long long l;
    cin >> l;
    while (l--) {
      long long a;
      cin >> a;
      a--;
      teams.push_back(a);
      r[i].push_back(a);
    }
  }
  sort((teams).begin(), (teams).end());
  teams.erase(unique((teams).begin(), (teams).end()), teams.end());
  while (1) {
    for (auto u : teams) used2[u] = rand() % 2 + 1;
    bool f = true;
    for (long long i = 0; i < n; i++) {
      mt[i] = -1;
      for (auto u : r[i]) {
        if (used[i] == used2[u]) mt[i] = u;
      }
      if (mt[i] == -1) f = false;
    }
    if (f) {
      for (long long i = 0; i < n; i++) cout << mt[i] << ' ';
      cout << '\n';
      for (auto u : teams) cout << used2[u] << ' ';
      return 0;
    }
  }
}
