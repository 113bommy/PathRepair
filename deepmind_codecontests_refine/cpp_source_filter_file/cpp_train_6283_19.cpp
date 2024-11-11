#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("-ffloat-store")
using namespace std;
clock_t time_p = clock();
void aryanc403() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
const long long int INF = 0xFFFFFFFFFFFFFFFL;
long long int seed;
mt19937 rng(seed = chrono::steady_clock::now().time_since_epoch().count());
inline long long int rnd(long long int l = 0, long long int r = INF) {
  return uniform_int_distribution<long long int>(l, r)(rng);
}
class CMP {
 public:
  bool operator()(pair<long long int, long long int> a,
                  pair<long long int, long long int> b) {
    return !(a.first < b.first || a.first == b.first && a.second <= b.second);
  }
};
void add(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  auto jt = m.find(x);
  if (jt == m.end())
    m.insert({x, cnt});
  else
    jt->second += cnt;
}
void del(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  auto jt = m.find(x);
  if (jt->second <= cnt)
    m.erase(jt);
  else
    jt->second -= cnt;
}
bool cmp(const pair<long long int, long long int> &a,
         const pair<long long int, long long int> &b) {
  return a.first < b.first || (a.first == b.first && a.second < b.second);
}
const long long int mod = 1000000007L;
const long long int maxN = 100000L;
long long int T, n, i, j, k, in, cnt, l, r, u, v, x, y;
long long int m;
string s;
vector<long long int> a, b;
map<long long int, long long int> mm;
long long int occ[maxN + 5];
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    cin >> n;
    a.clear();
    a.reserve(n);
    for (i = 0; i < (n); ++i) {
      cin >> in;
      occ[in] += i;
    }
    for (i = 0; i < (n); ++i) {
      cin >> in;
      occ[in] -= i;
      b.push_back(occ[in]);
    }
    for (i = (1); i <= (n); ++i) mm[occ[i]]++;
    ;
    for (i = 0; i < (n); ++i) {
      ;
      auto it = mm.lower_bound(-i);
      long long int ans = INF;
      ans = min(ans, abs(it->first + i));
      --it;
      ans = min(ans, abs(it->first + i));
      cout << ans << "\n";
      add(mm, b[i] + n);
      del(mm, b[i]);
    }
  }
  aryanc403();
  return 0;
}
