#include <bits/stdc++.h>
using namespace std;
class Debugger {
 public:
  template <typename T>
  Debugger &operator<<(const T &v) {
    cerr << v;
    return *this;
  }
  ~Debugger() { cerr << endl; }
};
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T, size_t N>
inline ostream &operator<<(ostream &os, const array<T, N> &a) {
  bool first = true;
  os << "[";
  for (auto &v : a) {
    if (!first) os << ", ";
    os << v;
    first = false;
  }
  os << "]";
  return os;
}
template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &v) {
  bool first = true;
  os << "[";
  for (unsigned int i = 0; i < v.size(); i++) {
    if (!first) os << ", ";
    os << v[i];
    first = false;
  }
  return os << "]";
}
template <typename T>
inline ostream &operator<<(ostream &os, const set<T> &v) {
  bool first = true;
  os << "{";
  for (typename set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
    if (!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "}";
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &v) {
  bool first = true;
  os << "[";
  for (typename map<T1, T2>::const_iterator ii = v.begin(); ii != v.end();
       ++ii) {
    if (!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "]";
}
const long long MOD = 1000000000 + 7;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long power_mod(long long x, long long y, long long p) {
  long long ans = 1;
  x %= p;
  while (y > 0) {
    if (y & 1) ans = (ans * x) % p;
    y >>= 1;
    x = (x * x) % p;
  }
  return ans;
}
inline long long modInverse(long long n, long long p) {
  return power_mod(n, p - 2, p);
}
long long nCrModP(vector<long long> &fac, long long n, long long r,
                  long long p) {
  if (r == 0) return 1;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
template <typename T>
void print_vector(const vector<T> &v) {
  for (int i = (0); i < (((int)(v).size())); i++) {
    if (i > 0) cout << "";
    cout << v[i];
  }
  cout << endl;
}
long long s[500005];
int n, x;
int solve() {
  s[0] = 0;
  int l = (n + 1) / 2;
  for (int i = (1); i < (l + 1); i++) {
    int val;
    cin >> val;
    s[i] = s[i - 1] + val;
  }
  cin >> x;
  for (int i = (l + 1); i < (n + 1); i++) {
    s[i] = s[i - 1] + x;
  }
  long long ans = s[n];
  for (int i = (n); i > (l - 1); i--) {
    if (ans > 0) return i;
    ans = min(ans - x, s[n] - s[n - i + 1]);
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  srand(time(NULL));
  cin.tie(NULL);
  cout.tie(NULL);
  while (cin >> n) cout << solve() << endl;
}
