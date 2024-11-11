#include <bits/stdc++.h>
using namespace std;
bool deb_mode = 0;
class debugger {
  vector<string> vars;

 public:
  template <typename T>
  debugger &operator,(const T v) {
    stringstream ss;
    ss << v, vars.push_back(ss.str());
    return *this;
  }
  void printall() {
    int j = 0, l = vars.size();
    for (int i = 0; i < (l - 1); i++) {
      if (i) cout << ", ";
      for (; j < vars[l - 1].size(); j++) {
        if (vars[l - 1][j] == ',') {
          j++;
          break;
        }
        cout << vars[l - 1][j];
      }
      cout << " = " << vars[i];
    }
    vars.clear();
  }
} Dbug;
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << "(" << p.first << "," << p.second << ")";
}
template <typename T>
inline ostream &operator<<(ostream &os, const vector<T> &v) {
  bool first = true;
  os << "{";
  for (unsigned int i = 0; i < v.size(); i++) {
    if (!first) os << ",";
    os << v[i];
    first = false;
  }
  return os << "}";
}
template <typename T>
inline ostream &operator<<(ostream &os, const set<T> &v) {
  bool first = true;
  os << "{";
  for (typename set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) {
    if (!first) os << ",";
    os << *ii;
    first = false;
  }
  return os << "}";
}
template <typename T1, typename T2>
inline ostream &operator<<(ostream &os, const map<T1, T2> &v) {
  bool first = true;
  os << "{";
  for (typename map<T1, T2>::const_iterator ii = v.begin(); ii != v.end();
       ++ii) {
    if (!first) os << ",";
    os << *ii;
    first = false;
  }
  return os << "}";
}
template <typename T>
void getarray(T a[], int b, int e) {
  for (int i = b; i < e + b; i++) cin >> a[i];
}
template <typename T>
void printarray(T a[], int b, int e) {
  for (int i = b; i < e - 1 + b; i++) cout << a[i] << " ";
  if (e - 1 + b >= 0) cout << a[e - 1 + b] << '\n';
}
template <typename T>
void printV(vector<T> v) {
  int sz = v.size();
  if (sz) cout << v[0];
  for (int i = 1; i < sz; i++) cout << " " << v[i];
  printf("\n");
}
template <typename T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename T>
T BigMod(T b, T p, T m) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    T s = BigMod(b, p / 2, m);
    return ((s % m) * (s % m)) % m;
  }
  return ((b % m) * (BigMod(b, p - 1, m) % m)) % m;
}
template <typename T>
T ModInv(T b, T m) {
  return BigMod(b, m - 2, m);
}
pair<long long int, pair<long long int, long long int> > ext_gcd(
    long long int a, long long int b) {
  if (b == 0) return make_pair(a, make_pair(1LL, 0LL));
  pair<long long int, pair<long long int, long long int> > t =
      ext_gcd(b, a % b);
  return make_pair(
      t.first,
      make_pair(t.second.second, t.second.first - a / b * t.second.second));
}
long long int ModInvNonPrimeM(long long int N, long long int M) {
  pair<long long int, pair<long long int, long long int> > r = ext_gcd(N, M);
  r.second.first %= M;
  if (r.second.first < 0) r.second.first += M;
  return r.second.first;
}
template <class T>
inline void read(T &x) {
  bool Minus = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') Minus = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (Minus) x = -x;
}
char getc() {
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  return c;
}
int CI(int &_x) { return scanf("%d", &_x); }
int CI(int &_x, int &_y) { return scanf("%d %d", &_x, &_y); }
int CI(int &_x, int &_y, int &_z) { return scanf("%d %d %d", &_x, &_y, &_z); }
int CI(int &_a, int &_b, int &_c, int &_d) {
  return scanf("%d %d %d %d", &_a, &_b, &_c, &_d);
}
template <class T1, class T2>
inline T1 UMAX(T1 &m, T2 other) {
  if (m < other) m = other;
  return m;
}
template <class T1, class T2>
inline T1 UMIN(T1 &m, T2 other) {
  if (m > other) m = other;
  return m;
}
template <class T>
string toString(T n) {
  ostringstream oss;
  oss << n;
  return oss.str();
}
int toInt(string s) {
  int r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
long long int toLong(string s) {
  long long int r = 0;
  istringstream sin(s);
  sin >> r;
  return r;
}
bool isVowel(char ch) {
  ch = tolower(ch);
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    return true;
  return false;
}
bool isUpper(char c) { return c >= 'A' && c <= 'Z'; }
bool isLower(char c) { return c >= 'a' && c <= 'z'; }
int dr8[8] = {+1, -1, +0, +0, +1, -1, -1, +1};
int dc8[8] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dr4[4] = {+0, +0, +1, -1};
int dc4[4] = {-1, +1, +0, +0};
int kn8r[8] = {+1, +2, +2, +1, -1, -2, -2, -1};
int kn8c[8] = {+2, +1, -1, -2, -2, -1, +1, +2};
const double EPS = 1e-9;
const int INF = (1 << 30) - 1;
const long long int LINF = (1ll << 62) - 1;
const int mod = (int)1e9 + 7;
const int MAX = (int)1e5;
int N, M, X;
int main() {
  if (deb_mode) srand(int(time(NULL)));
  int i, j, k, l, n, m, q, a, b, c;
  cin >> N >> M >> X;
  X--;
  if (N > M) {
    cout << "0\n";
    return 0;
  }
  int DP[2][N + 5][N + 5];
  memset(DP, 0, sizeof(DP));
  DP[M & 1][N][0] = 1;
  int posNow, posPrev;
  for (int pos = M; pos >= 0; pos--) {
    posNow = pos & 1;
    posPrev = (pos - 1) & 1;
    for (i = 0; i < N + 1; i++)
      for (j = 0; j < N + 1; j++) DP[posPrev][i][j] = 0;
    for (int seg = N; seg >= 0; seg--) {
      for (int open = N; open >= 0; open--) {
        if (open)
          DP[posPrev][seg][open - 1] =
              (DP[posPrev][seg][open - 1] + DP[posNow][seg][open]) % mod;
        if (pos - 1 != X && seg)
          DP[posPrev][seg - 1][open + 1] =
              (DP[posPrev][seg - 1][open + 1] + DP[posNow][seg][open]) % mod;
        if (seg)
          DP[posPrev][seg - 1][open] =
              (DP[posPrev][seg - 1][open] + DP[posNow][seg][open]) % mod;
        if (pos - 1 != X)
          DP[posPrev][seg][open] =
              (DP[posPrev][seg][open] + DP[posNow][seg][open]) % mod;
      }
    }
  }
  long long int ANS = DP[posNow][0][0];
  for (i = 1; i <= N; i++) ANS = (ANS * i) % mod;
  cout << ANS << "\n";
  if (deb_mode)
    cerr << "EXECUTION TIME = " << (1.0 * clock()) / CLOCKS_PER_SEC
         << " SECONDS\n";
  return 0;
}
