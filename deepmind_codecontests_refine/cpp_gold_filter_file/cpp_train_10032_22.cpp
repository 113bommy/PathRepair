#include <bits/stdc++.h>
using namespace std;
struct edje {
  int from, to;
  long long w;
  edje(int from, int to, long long w) : from(from), to(to), w(w) {}
  bool operator<(const edje& e) const { return w < e.w; }
};
const long long oo = (long long)((1e18) + 1);
const double eps = 1e-9;
const long long mod7 = 1000000007;
long long mod(long long a, long long b) { return (a % b + b) % b; }
long long strTonumModa(string s, long long athemod) {
  long long ans = 0;
  for (long long i = 0; i < ((long long)s.size()); i++) {
    ans = (ans * 10 + s[i] - '0') % athemod;
  }
  return ans;
}
long long mod_exp(long long base, long long p, long long MOD) {
  if (p == 0) return 1;
  if (p == 1) return base;
  long long ret = mod_exp(base, p / 2, MOD) % MOD;
  ret = (ret * ret) % MOD;
  if (p % 2 == 1) ret = (ret * base) % MOD;
  return ret;
}
string getstr(long long x) {
  stringstream ss;
  ss << x;
  string str = ss.str();
  return str;
}
bool comp(pair<long long, pair<long long, long long> > a,
          pair<long long, pair<long long, long long> > b) {
  return a.first > b.first;
}
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long sq(long long n) { return n * n; }
set<long long> s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < (int)(n); ++i) cin >> a[i];
  vector<long long> v;
  v.push_back(a[0]);
  for (int i = (1); i < (int)(n); ++i)
    if (a[i] != a[i - 1]) v.push_back(a[i]);
  for (int i = 0; i < ((long long)v.size()); ++i) {
    long long ored = v[i];
    s.insert(ored);
    int l = 1, j = i + 1;
    while (l < 64 && j < ((long long)v.size())) {
      ored |= v[j];
      s.insert(ored);
      j++;
      l++;
    }
  }
  cout << s.size() << endl;
  return 0;
}
