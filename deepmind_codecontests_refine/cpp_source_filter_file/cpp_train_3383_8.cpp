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
      for (j; j < vars[l - 1].size(); j++) {
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
const int MAX = (int)1e6;
bool status[MAX + 7];
int primes[MAX + 7], plndrm[MAX + 7];
void sieve() {
  status[1] = 1;
  for (int i = 2; i * i <= MAX; i++)
    if (status[i] == 0)
      for (int j = i + i; j <= MAX; j += i) status[j] = 1;
}
int Rev(int n) {
  int m = 0;
  while (n) {
    m = m * 10 + n % 10;
    n /= 10;
  }
  return m;
}
void pal() {
  for (int i = 1; i <= MAX; i++) {
    plndrm[i] = plndrm[i - 1];
    primes[i] = primes[i - 1];
    if (Rev(i) == i) plndrm[i]++;
    if (status[i] == 0) primes[i]++;
  }
}
int main() {
  if (deb_mode) srand(int(time(NULL)));
  int i, j, k, l, n, m, q, c;
  sieve();
  pal();
  long long int a, b;
  read(a), read(b);
  int ans = 0;
  for (i = 1; i <= MAX; i++)
    if (primes[i] * b <= plndrm[i] * a) ans = i;
  if (ans == 0)
    cout << "Palindromic tree is better than splay tree\n";
  else
    cout << ans << "\n";
  if (deb_mode) cerr << "TIME = " << clock() << " ms" << '\n';
  return 0;
}
