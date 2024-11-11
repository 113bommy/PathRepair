#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("-ffloat-store")
using namespace std;
const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403() {}
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
    return !(a.first < b.first || (a.first == b.first && a.second <= b.second));
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
const long long int L = 20;
long long int T, n, i, j, k, in, cnt, l, r, u, v, x, y;
long long int m;
string s;
vector<long long int> a;
vector<vector<long long int> > hashes, prefHash;
void getHash(vector<long long int> &a) {
  a.clear();
  a.resize(L);
  for (auto &x : a) x = rnd(0, 2);
}
void getXOR(vector<long long int> &ans, vector<long long int> &a,
            vector<long long int> &b) {
  for (long long int i = 0; i < L; ++i) ans[i] = (a[i] + b[i]) % 3;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    cin >> n;
    hashes.resize(n + 1);
    for (auto &v : hashes) getHash(v);
    ;
    a.clear();
    a.reserve(n + 1);
    prefHash.resize(n + 1, vector<long long int>(L, 0));
    a.push_back(0);
    prefHash[0] = hashes[0];
    for (i = (1); i <= (n); ++i) {
      cin >> in;
      a.push_back(in);
      getXOR(prefHash[i], prefHash[i - 1], hashes[in]);
    };
    vector<long long int> freq(n + 1, 0);
    map<vector<long long int>, long long int> hval;
    long long int l = 1;
    long long int ans = 0;
    hval[prefHash[0]]++;
    for (long long int i = 1; i <= n; ++i) {
      freq[a[i]]++;
      while (l < i && freq[a[i]] > 3) {
        freq[a[l]]--;
        hval[prefHash[l - 1]]--;
        l++;
      };
      ans += hval[prefHash[i]];
      hval[prefHash[i]]++;
    }
    cout << ans << "\n";
  }
  aryanc403();
  return 0;
}
