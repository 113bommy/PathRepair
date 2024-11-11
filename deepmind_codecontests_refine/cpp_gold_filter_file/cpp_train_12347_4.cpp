#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 3;
const int SQRT = 320;
const int MOD = 1e9 + 7;
const int INF = MOD;
const long double PI = 3.141592653589793;
const long double EPS = 1e-6;
int sieve[2 * maxn];
long long n[4];
long long m[4];
long long s[4];
vector<pair<int, int>> ss;
vector<pair<int, int>> nn;
vector<pair<int, int>> mm;
void merge(vector<pair<int, int>>& to, vector<pair<int, int>> from) {
  vector<pair<int, int>> tmp;
  int fi = 0;
  int se = 0;
  while (fi < to.size() && se < from.size()) {
    if (to[fi].first < from[se].first) {
      tmp.push_back(to[fi]);
      ++fi;
    } else if (to[fi].first == from[se].first) {
      tmp.push_back({to[fi].first, to[fi].second + from[se].second});
      ++fi;
      ++se;
    } else {
      tmp.push_back(from[se]);
      ++se;
    }
  }
  while (se < from.size()) {
    tmp.push_back(from[se]);
    ++se;
  }
  while (fi < to.size()) {
    tmp.push_back(to[fi]);
    ++fi;
  }
  to = tmp;
}
long long pw(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    b >>= 1;
    a *= a;
  }
  return ans;
}
vector<pair<int, int>> factorize(int val) {
  vector<pair<int, int>> tmp;
  int last = 1;
  int k = val;
  while (k != 1) {
    int z = sieve[k];
    if (!z) {
      if (last != k) {
        tmp.push_back({k, 1});
      } else {
        tmp.back().second++;
      }
      break;
    } else {
      if (last == z) {
        tmp.back().second++;
      } else {
        tmp.push_back({z, 1});
        last = z;
      }
    }
    k /= z;
  }
  return tmp;
}
long long ni;
long long sgn(long long pw) {
  if (pw & 1) return -1;
  return 1;
}
long long ans1 = 0;
void rec(long long cur, int pos) {
  if (pos == ss.size()) {
    if (cur <= ni) ++ans1;
    return;
  }
  long long goes = 1;
  for (int i = 0; i <= ss[pos].second; ++i) {
    rec(cur * goes, pos + 1);
    goes *= ss[pos].first;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 2; i <= 2000000; ++i) {
    if (!sieve[i] && i <= 5000) {
      for (int j = i * i; j <= 2000000; j += i) {
        if (!sieve[j]) {
          sieve[j] = i;
        }
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    nn.clear();
    ss.clear();
    mm.clear();
    ans1 = 0;
    for (int i = 1; i <= 3; ++i) cin >> n[i];
    for (int i = 1; i <= 3; ++i) cin >> m[i];
    for (int i = 1; i <= 3; ++i) cin >> s[i];
    s[1] *= 2;
    for (int i = 1; i <= 3; ++i) {
      merge(nn, factorize(n[i]));
      merge(ss, factorize(s[i]));
    }
    long long mi = m[1] * m[2] * m[3];
    ni = n[1] * n[2] * n[3];
    vector<long long> bad;
    int it_s = 0;
    for (int it_n = 0; it_n < nn.size(); ++it_n) {
      while (it_s < ss.size() && ss[it_s].first < nn[it_n].first) ++it_s;
      if (it_s < ss.size() && ss[it_s].first == nn[it_n].first) {
        if (ss[it_s].second < nn[it_n].second)
          bad.push_back(pw(ss[it_s].first, ss[it_s].second + 1));
      } else
        bad.push_back(nn[it_n].first);
    }
    int sz = bad.size();
    long long ans = mi;
    for (int msk = 1; msk < (1 << sz); ++msk) {
      long long k = 1;
      for (int i = 0; i < bad.size(); ++i) {
        if (msk & (1 << i)) k *= bad[i];
      }
      long long col = mi / k;
      ans += sgn(__builtin_popcount(msk)) * col;
    }
    rec(1, 0);
    cout << ans1 + ans << "\n";
  }
}
