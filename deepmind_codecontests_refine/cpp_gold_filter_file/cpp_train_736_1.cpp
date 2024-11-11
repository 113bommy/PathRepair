#include <bits/stdc++.h>
const int N = (int)2e5 + 7;
const int N_ = (int)2e3 + 1;
const int MAXN = 2016 * 2016;
const int MOD = (int)1e9;
const int INF = (int)2e9;
const int DEL = (int)3e5;
const int LOG = 20;
const int SIZE = 790;
const int ALPH = 256;
const int DIGIT = 10;
const int BLOCK = 300;
const int LIGHT = 650;
const long long LINF = (int64_t)2e18;
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-2;
using namespace std;
template <typename T>
T sqr(T a) {
  return a * a;
}
template <typename T>
bool uax(T &a, const T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool uin(T &a, const T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> &p) {
  out << p.first << ' ' << p.second;
  return out;
}
int n, a[N], b[N], t[N];
map<pair<int, pair<int, int>>, int> need;
void read() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) cin >> b[i];
}
void precalc() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        for (int g = 0; g < 4; g++) {
          if ((i | g) == j && (i & g) == k) {
            need[make_pair(i, make_pair(j, k))] = g;
          }
        }
      }
    }
  }
}
void get_try() {
  for (int i = 1; i < n; i++) {
    if (need.count(make_pair(t[i - 1], make_pair(a[i - 1], b[i - 1]))) == 0)
      return;
    t[i] = need[make_pair(t[i - 1], make_pair(a[i - 1], b[i - 1]))];
  }
  cout << "Yes\n";
  for (int i = 0; i < n; i++) cout << t[i] << ' ';
  exit(0);
}
void solve() {
  precalc();
  for (int i = 0; i < 4; i++) {
    t[0] = i;
    get_try();
  }
  cout << "No";
}
void check_time() {
  double start = clock();
  read(), solve();
  cout << "\nTime is " << (clock() - start) * 1.0 / CLOCKS_PER_SEC << "s\n";
}
int main() {
  cout << fixed << setprecision(20);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  read();
  solve();
}
