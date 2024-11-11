#include <bits/stdc++.h>
using namespace std;
using namespace std;
inline long long __gcd(long long a, long long b);
void pdash(int n = 1);
int bitcount(long long u);
long long power(long long x, long long y);
long long power(long long x, long long y, long long z);
long long modInverse(long long n, long long p);
long long nCrF(long long n, long long r, long long p);
vector<int> cordinate_compression(vector<int>& v);
void make_uniquee(vector<int>& vec);
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
long long myrand(long long mod = 1000000009);
void custome_random_shuffle(vector<int>& vec) {
  shuffle(vec.begin(), vec.end(), rng);
  return;
}
void svec(vector<int>& vec);
void smap(vector<int, int>& mp);
void sset(set<int>& st);
vector<vector<long long> > dp;
vector<vector<pair<int, long long> > > vec;
int n, k;
void bfs(int curr, int parent) {
  vector<long long> val;
  for (auto& j : vec[curr])
    if (j.first ^ parent) {
      bfs(j.first, curr);
      val.push_back(dp[j.first][1] + j.second);
    }
  sort(val.rbegin(), val.rend());
  long long sum = 0, nxt = 0;
  for (int i = 0; i < min(k - 1, (int)((val).size())); i++) {
    sum += val[i];
  }
  if ((int)((val).size()) >= k) nxt = val[k - 1];
  dp[curr][0] = dp[curr][1] = sum;
  for (auto& j : vec[curr])
    if (j.first ^ parent)
      dp[curr][0] =
          max(dp[curr][0], sum - max(0ll, dp[j.first][1] + j.second - nxt) +
                               dp[j.first][0] + j.second);
}
void solve() {
  cin >> n >> k;
  vec = vector<vector<pair<int, long long> > >(n + 1,
                                               vector<pair<int, long long> >());
  dp = vector<vector<long long> >(n + 1, vector<long long>(2));
  for (int i = 1; i < n; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a++;
    b++;
    vec[a].push_back({b, w});
    vec[b].push_back({a, w});
  }
  bfs(1, 0);
  cout << max(dp[1][0], dp[1][1]) << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
inline long long __gcd(long long a, long long b) {
  if (a == 0 || b == 0) {
    return a + b;
  }
  long long tempa, tempb;
  while (1) {
    if (a % b == 0)
      return b;
    else {
      tempa = a;
      tempb = b;
      a = tempb;
      b = tempa % tempb;
    }
  }
}
void pdash(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 30; j++) {
      cout << "-";
    }
    cout << "\n";
  }
}
long long power(long long x, long long y) {
  long long result = 1;
  while (y > 0) {
    if (y & 1) {
      result = (result * x);
    }
    y = y >> 1;
    x = (x * x);
  }
  return result;
}
long long power(long long x, long long y, long long z) {
  long long result = 1;
  x = x % z;
  while (y > 0) {
    if (y & 1) {
      result = (result * x) % z;
    }
    y = y >> 1;
    x = (x * x) % z;
  }
  return result;
}
long long modInverse(long long n, long long p) { return power(n, p - 2, p); }
long long nCrF(long long n, long long r, long long p) {
  if (r == 0) return 1;
  vector<long long> f(n + 1);
  f[0] = 1;
  for (long long i = 1; i <= n; i++) f[i] = f[i - 1] * i % p;
  return (f[n] * modInverse(f[r], p) % p * modInverse(f[n - r], p) % p) % p;
}
vector<int> cordinate_compression(vector<int>& v) {
  vector<int> p = v;
  make_uniquee(p);
  for (int i = 0; i < (int)((v).size()); i++)
    v[i] = (int)(lower_bound(p.begin(), p.end(), v[i]) - p.begin());
  return p;
}
long long myrand(long long mod) { return rng() % mod; }
void make_uniquee(vector<int>& vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
int bitcount(long long u) {
  int cnt = 0;
  while (u) {
    u = u & (u - 1);
    cnt++;
  }
  return cnt;
}
void svec(vector<int>& vec) {
  cout << "{\n";
  for (int i = 0; i < (int)((vec).size()); i++)
    cout << "[" << i << "]  = " << vec[i] << "\n";
  cout << "}\n";
}
void sset(set<int>& st) {
  cout << "{\n";
  for (auto& j : st) {
    cout << j << "\n";
  }
  cout << "}\n";
}
void smap(map<int, int>& mp) {
  cout << "{\n";
  for (auto& j : mp) cout << "[" << j.first << "]  = " << j.second << "\n";
  cout << "}\n";
}
