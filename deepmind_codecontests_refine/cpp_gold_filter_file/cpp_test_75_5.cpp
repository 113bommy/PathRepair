#include <bits/stdc++.h>
using namespace std;
mt19937 mr(time(0));
struct LL {
  static long long int m;
  long long int val;
  LL(long long int v) { val = reduce(v); };
  LL(int v) { val = reduce((long long int)v); };
  LL() { val = 0; };
  ~LL(){};
  LL(const LL& l) { val = l.val; };
  LL& operator=(int l) {
    val = l;
    return *this;
  }
  LL& operator=(long long int l) {
    val = l;
    return *this;
  }
  LL& operator=(LL l) {
    val = l.val;
    return *this;
  }
  static void setMod(long long int m) {
    assert(m);
    LL::m = m;
  }
  static long long int reduce(long long int x, long long int md = m) {
    x %= md;
    while (x >= md) x -= md;
    while (x < 0) x += md;
    return x;
  }
  bool operator<(const LL& b) { return val < b.val; }
  bool operator<=(const LL& b) { return val <= b.val; }
  bool operator!=(const LL& b) { return val != b.val; }
  bool operator==(const LL& b) { return val == b.val; }
  bool operator>=(const LL& b) { return val >= b.val; }
  bool operator>(const LL& b) { return val > b.val; }
  LL operator+(const LL& b) { return LL(val + b.val); }
  LL operator+(const long long int& b) { return (*this + LL(b)); }
  LL& operator+=(const LL& b) { return (*this = *this + b); }
  LL& operator+=(const long long int& b) { return (*this = *this + b); }
  LL operator-(const LL& b) { return LL(val - b.val); }
  LL operator-(const long long int& b) { return (*this - LL(b)); }
  LL& operator-=(const LL& b) { return (*this = *this - b); }
  LL& operator-=(const long long int& b) { return (*this = *this - b); }
  LL operator*(const LL& b) { return LL(val * b.val); }
  LL operator*(const long long int& b) { return (*this * LL(b)); }
  LL& operator*=(const LL& b) { return (*this = *this * b); }
  LL& operator*=(const long long int& b) { return (*this = *this * b); }
  static LL exp(const LL& x, const long long int& y) {
    long long int z = y;
    z = reduce(z, m - 1);
    LL ret = 1;
    LL w = x;
    while (z) {
      if (z & 1) ret *= w;
      z >>= 1;
      w *= w;
    }
    return ret;
  }
  LL& operator^=(long long int y) { return (*this = LL(val ^ y)); }
  LL operator/(const LL& b) { return ((*this) * exp(b, -1)); }
  LL operator/(const long long int& b) { return (*this / LL(b)); }
  LL operator/=(const LL& b) { return ((*this) *= exp(b, -1)); }
  LL& operator/=(const long long int& b) { return (*this = *this / LL(b)); }
};
ostream& operator<<(ostream& os, const LL& obj) { return os << obj.val; }
long long int LL::m = 1000000007;
using namespace std;
long long int cases, N, M, Q, K, X, Y;
long long int rd() {
  long long int x;
  cin >> x;
  return x;
}
double rdd() {
  double x;
  cin >> x;
  return x;
}
string rds() {
  string x;
  cin >> x;
  return x;
}
template <class T>
void rds(char* S, T* sz) {
  *sz = strlen(strcpy(S, rds().c_str()));
}
template <class T>
void rG(int sz, vector<vector<T>>& adj, int E = -18852946) {
  if (E == -18852946) E = sz - 1;
  adj.clear();
  for (long long int i = 0; i < sz + 1; ++i) adj.push_back(vector<T>());
  for (long long int i = 0; i < E; ++i) {
    T a = rd();
    T b = rd();
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}
void fl() { cout.flush(); }
template <class T>
void ds(vector<T> v) {
  for (auto x : v) cout << x << " ";
  cout << endl;
}
template <class T>
void panic(T out) {
  cout << out << endl;
  exit(0);
}
template <class S, class T>
bool updmin(S& a, T b) {
  S B = (S)b;
  if (B < a) {
    a = B;
    return 1;
  }
  return 0;
}
template <class S, class T>
bool updmax(S& a, T b) {
  S B = (S)b;
  if (B > a) {
    a = B;
    return 1;
  }
  return 0;
}
template <class S, class T>
S min(S a, T b) {
  S c = a;
  updmin(c, b);
  return c;
}
template <class S, class T>
S max(S a, T b) {
  S c = a;
  updmax(c, b);
  return c;
}
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
void precalc() {}
void reset() {}
bool cmp(pair<int, int> a, pair<int, int> b) {}
int L, A, B, R;
int S[3 * 100010];
void read() {
  N = rd();
  for (long long int i = 1; i <= N; ++i) S[i] = rd();
  S[0] = S[N + 1] = -99999;
  L = 1;
  R = N;
  for (A = 1; S[A + 1] > S[A]; A++) {
  }
  for (B = N; S[B - 1] > S[B]; B--) {
  }
  cout << ((((A - 1) & 1) && ((N - B) & 1)) ? "Bob" : "Alice") << endl;
}
int main() {
  precalc();
  bool trials = 0;
  bool interactive = 0;
  if (!interactive) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  }
  if (trials)
    cases = rd();
  else
    cases = 1;
  while (cases--) {
    read();
  }
}
