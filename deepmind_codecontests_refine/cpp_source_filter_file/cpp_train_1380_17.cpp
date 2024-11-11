#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename T>
T sqr(T a) {
  return a * a;
}
template <typename T>
int sign(T a) {
  if (a == 0) return 0;
  return (a > 0 ? 1 : -1);
}
template <typename T>
bool uax(T& a, const T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool uin(T& a, const T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& p) {
  out << p.first << ' ' << p.second;
  return out;
}
mt19937_64 rnd(0);
const int LOG = 64;
const int N = (int)2e5 + 7;
const int MAXN = (int)1e6 + 7;
const int MOD = (int)1e9 + 7;
const int INF = (int)2e9 + 7;
const int CONST = 450;
const long long LINF = (int64_t)1e18;
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1;
long long n, val[13];
vector<int> mask;
void rec(int x, int len, int cnt) {
  if (len == 13) {
    if (cnt == 6) mask.push_back(x);
    return;
  }
  rec(2 * x, len + 1, cnt);
  rec(2 * x + 1, len + 1, cnt + 1);
}
void solve() {
  cin >> n;
  rec(0, 0, 0);
  for (int i = 0; i < 13; i++) {
    vector<int> pos;
    for (int j = 0; j < n; j++) {
      if (mask[j] & (1 << i)) continue;
      pos.push_back(j + 1);
    }
    if ((int)pos.size() == 0) continue;
    cout << "? " << (int)pos.size() << ' ';
    for (int x : pos) cout << x << ' ';
    cout << endl;
    cin >> val[i];
  }
  cout << "! ";
  for (int i = 0; i < n; i++) {
    int x = 0;
    for (int j = 0; j < 13; j++) {
      if (mask[i] & (1 << j)) x |= val[j];
    }
    cout << x << ' ';
  }
  cout << endl;
}
int main() {
  double start = clock();
  cout << fixed << setprecision(20);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  rnd.seed(time(0));
  int t = 1;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
