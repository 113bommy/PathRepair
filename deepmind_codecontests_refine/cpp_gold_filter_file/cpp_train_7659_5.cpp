#include <bits/stdc++.h>
using namespace std;
using namespace std;
inline long long __gcd(long long a, long long b);
void pdash(long long n = 1);
long long bitcount(long long u);
long long power(long long x, long long y);
long long power(long long x, long long y, long long z);
long long modInverse(long long n, long long p);
long long nCrF(long long n, long long r, long long p);
vector<long long> cordinate_compression(vector<long long>& v);
void make_uniquee(vector<long long>& vec);
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
long long myrand(long long mod = 1000000009);
void custome_random_shuffle(vector<long long>& vec) {
  shuffle(vec.begin(), vec.end(), rng);
  return;
}
void svec(vector<long long>& vec);
void smap(vector<long long, long long>& mp);
void sset(set<long long>& st);
vector<vector<long long> > vec;
vector<long long> val;
vector<long long> val_on_processing;
long long s;
long long ans = 0;
pair<long long, long long> bfs(long long curr, long long par) {
  long long coverable_child = val[curr] - 1;
  if (par == 0) coverable_child++;
  vector<long long> temp1, temp2;
  for (auto& j : vec[curr])
    if (j ^ par) {
      auto k = bfs(j, curr);
      if (k.first) temp1.push_back(k.first);
      if (k.second) temp2.push_back(k.second);
    }
  sort(temp1.begin(), temp1.end());
  sort(temp2.begin(), temp2.end());
  long long val1 = 0, ccnt = 0;
  while (coverable_child and temp1.size()) {
    val1 += (temp1.back() + 1);
    temp1.pop_back();
    coverable_child--;
    ccnt++;
  }
  while (coverable_child and temp2.size()) {
    long long p = min(temp2.back(), coverable_child);
    val1 += p * 2;
    temp2.pop_back();
    coverable_child -= p;
    ccnt += p;
  }
  return {val1 + (par != 0), (val[curr] - ccnt - (par != 0))};
}
void solve() {
  long long n;
  cin >> n;
  val.assign(n + 1, 0);
  val_on_processing = val;
  for (long long i = 1; i <= n; i++) cin >> val[i];
  vec = vector<vector<long long> >(n + 1, vector<long long>());
  for (long long i = 1; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  cin >> s;
  cout << bfs(s, 0).first << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
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
void pdash(long long n) {
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 30; j++) {
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
vector<long long> cordinate_compression(vector<long long>& v) {
  vector<long long> p = v;
  make_uniquee(p);
  for (long long i = 0; i < (long long)((v).size()); i++)
    v[i] = (long long)(lower_bound(p.begin(), p.end(), v[i]) - p.begin());
  return p;
}
long long myrand(long long mod) { return rng() % mod; }
void make_uniquee(vector<long long>& vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
long long bitcount(long long u) {
  long long cnt = 0;
  while (u) {
    u = u & (u - 1);
    cnt++;
  }
  return cnt;
}
void svec(vector<long long>& vec) {
  cout << "{\n";
  for (long long i = 0; i < (long long)((vec).size()); i++)
    cout << "[" << i << "]  = " << vec[i] << "\n";
  cout << "}\n";
}
void sset(set<long long>& st) {
  cout << "{\n";
  for (auto& j : st) {
    cout << j << "\n";
  }
  cout << "}\n";
}
void smap(map<long long, long long>& mp) {
  cout << "{\n";
  for (auto& j : mp) cout << "[" << j.first << "]  = " << j.second << "\n";
  cout << "}\n";
}
