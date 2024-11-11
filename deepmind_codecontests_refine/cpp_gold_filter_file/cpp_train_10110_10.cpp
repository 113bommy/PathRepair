#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1E9;
const long long LINF = (long long)4E18;
const long double PI = acos(-1.0);
const long double EPS = 1E-11;
template <typename T>
T gcd(T a, T b) {
  return (b == 0) ? abs(a) : gcd(b, a % b);
}
template <typename T>
inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <typename T>
inline T mod(T a, T b) {
  a %= b;
  if (a < 0) a += b;
  return a;
}
template <typename T>
inline T sheapr(T x) {
  return x * x;
}
template <typename T>
inline T gmax(T a, T b) {
  return (a > b ? a : b);
}
template <typename T>
inline T gmin(T a, T b) {
  return (a < b ? a : b);
}
template <typename T>
inline string toString(T x) {
  ostringstream oss;
  oss << x;
  return oss.str();
}
inline long long toInt(const string& st) {
  istringstream iss(st);
  long long x;
  iss >> x;
  return x;
}
inline long double toDouble(const string& st) {
  istringstream iss(st);
  long double x;
  iss >> x;
  return x;
}
inline string toLower(string st) {
  for (int i = 0; i < (((int)(st).size())); i++) st[i] = tolower(st[i]);
  return st;
}
inline string toUpper(string st) {
  for (int i = 0; i < (((int)(st).size())); i++) st[i] = toupper(st[i]);
  return st;
}
bool LOCAL = false, OUTPUT = true;
const char DEBUG_PARAM[] = "__LOCAL_TESTING";
const char IN[] = "_.in";
const char OUT[] = "_.out";
inline void init();
inline void run();
int ntest = 0, test;
int main(int argc, char* argv[]) {
  if (argc > 1 && strcmp(argv[1], DEBUG_PARAM) == 0) {
    LOCAL = true;
    freopen(IN, "r", stdin);
  }
  init();
  if (ntest == 0) {
    cerr << "ntest = ?" << endl;
    return 0;
  }
  for (test = 1; test <= ntest; ++test) {
    run();
  }
  return 0;
}
inline void stop() { ntest = test - 1; }
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
inline void init() {
  OUTPUT = true;
  ntest = 1;
}
int n, m;
double k;
map<string, int> mp;
inline void run() {
  cin >> n >> m >> k;
  string skill;
  double value;
  for (int i = 0; i < (n); i++) {
    cin >> skill >> value;
    int x = (int)(value * k + EPS);
    if (x >= 100) {
      mp[skill] = x;
    }
  }
  for (int i = 0; i < (m); i++) {
    cin >> skill;
    if (!mp.count(skill)) {
      mp[skill] = 0;
    }
  }
  cout << ((int)(mp).size()) << endl;
  for (typeof((mp).begin()) it = (mp).begin(); it != (mp).end(); ++it) {
    cout << it->first << " " << it->second << endl;
  }
}
