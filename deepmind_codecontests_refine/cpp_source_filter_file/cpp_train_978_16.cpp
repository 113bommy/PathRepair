#include <bits/stdc++.h>
#pragma GCC optimize("O500")
#pragma comment(linker, "/STACK:1677777216")
#pragma warning(default : 4)
using namespace std;
const double eps = 1e-12;
const int oo = 0x3F3F3F3F;
const long long ooLL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1000000007;
template <typename T>
T sqr(T x) {
  return x * x;
}
template <typename T>
void debpr(const T &);
template <typename T1, typename T2>
void debpr(const pair<T1, T2> &);
template <typename T1, typename T2>
void debpr(const vector<T1, T2> &);
template <typename T>
void debpr(const set<T> &);
template <typename T1, typename T2>
void debpr(const map<T1, T2> &);
template <typename T>
void prcont(T be, T en, const string &st, const string &fi, const string &mi) {
  debpr(st);
  bool ft = 0;
  while (be != en) {
    if (ft) debpr(mi);
    ft = 1;
    debpr(*be);
    ++be;
  }
  debpr(fi);
}
template <typename T>
void debpr(const T &a) {}
template <typename T1, typename T2>
void debpr(const pair<T1, T2> &p) {
  debpr("(");
  debpr(p.first);
  debpr(", ");
  debpr(p.second);
  debpr(")");
}
template <typename T1, typename T2>
void debpr(const vector<T1, T2> &a) {
  prcont(a.begin(), a.end(), "[", "]", ", ");
}
template <typename T>
void debpr(const set<T> &a) {
  prcont(a.begin(), a.end(), "{", "}", ", ");
}
template <typename T1, typename T2>
void debpr(const map<T1, T2> &a) {
  prcont(a.begin(), a.end(), "{", "}", ", ");
}
void deb(){};
template <typename T1>
void deb(const T1 &t1) {
  debpr(t1);
  debpr('\n');
}
template <typename T1, typename T2>
void deb(const T1 &t1, const T2 &t2) {
  debpr(t1);
  debpr(' ');
  debpr(t2);
  debpr('\n');
}
template <typename T1, typename T2, typename T3>
void deb(const T1 &t1, const T2 &t2, const T3 &t3) {
  debpr(t1);
  debpr(' ');
  debpr(t2);
  debpr(' ');
  debpr(t3);
  debpr('\n');
}
template <typename T1, typename T2, typename T3, typename T4>
void deb(const T1 &t1, const T2 &t2, const T3 &t3, const T4 &t4) {
  debpr(t1);
  debpr(' ');
  debpr(t2);
  debpr(' ');
  debpr(t3);
  debpr(' ');
  debpr(t4);
  debpr('\n');
}
const double PI = acos(-1.);
long long Round(double x) { return x < 0 ? x - .5 : x + .5; }
template <typename T>
void ass(bool v, const T &x, string m = "Fail") {
  if (!v) {
    deb(m);
    deb(x);
    throw;
  }
}
int main() {
  void run();
  run();
  return 0;
}
long long a[1 << 20];
int n;
long long gcd(long long a, long long b) {
  long long t;
  while (a) b %= a, t = a, a = b, b = t;
  return b;
}
long long mrand() {
  long long rs = 0;
  for (int i = (0), _b(60); i < _b; ++i)
    if (rand() % 2) rs += 1LL << i;
  return rs;
}
void run() {
  scanf("%d", &n);
  for (int i = (0), _b(n); i < _b; ++i) scanf("%lld", &a[i]);
  long long rs = 1;
  srand(1);
  for (int it = (0), _b(12); it < _b; ++it) {
    long long t = a[mrand() % n];
    unordered_map<long long, int> m;
    m.reserve(1 << 15);
    for (int i = (0), _b(n); i < _b; ++i) ++m[gcd(a[i], t)];
    vector<pair<long long, long long> > v((m).begin(), (m).end());
    for (int i = (0), _b(v.size()); i < _b; ++i) {
      int z = 0;
      for (int j = (0), _b(v.size()); j < _b; ++j)
        if (v[j].first % v[i].first == 0) z += v[j].second;
      if (z >= (n + 1) / 2) rs = max(rs, v[i].first);
    }
  }
  cout << rs << endl;
}
