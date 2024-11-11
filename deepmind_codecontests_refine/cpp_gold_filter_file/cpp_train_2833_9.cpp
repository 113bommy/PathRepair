#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int (*itoi)(int);
typedef int (*iitoi)(int, int);
typedef int (*iiitoi)(int, int, int);
typedef ll (*ltol)(ll);
typedef ll (*lltol)(ll, ll);
typedef ll (*llltol)(ll, ll, ll);
const long double PI = acos(0) * 2;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;
int X4[] = {-1, 0, 1, 0}, Y4[] = {0, -1, 0, 1};
int X8[] = {-1, -1, -1, 0, 1, 1, 1, 0}, Y8[] = {-1, 0, 1, 1, 1, 0, -1, -1};
template <typename T>
inline bool uax(T& a, T b) {
  return a < b ? (a = b, 1) : 0;
}
template <typename T>
inline bool uin(T& a, T b) {
  return a > b ? (a = b, 1) : 0;
}
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
  return is >> p.first >> p.second;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  return os << '(' << p.first << ", " << p.second << ")";
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (int i = 0; i < (int)v.size(); i++) {
    os << v[i];
    if (i + 1 < (int)v.size()) os << ' ';
  }
  return os;
}
const int MOD = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << std::setprecision(10);
  cout << fixed;
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    string s;
    cin >> s;
    int n = s.size();
    ll len = n;
    vector<int> num(x + 1, 0);
    for (int i = 1; i <= min(x, n); i++) {
      num[i] = s[i - 1] - '0';
    }
    bool filled = 0;
    for (int l = 1; l <= x; l++) {
      int rep = num[l];
      if (!filled) {
        int L = l + 1, R = len, p = len + 1;
        for (int _i = 0; _i < (rep - 1); _i++) {
          for (int i = L; i <= R; i++) {
            if (p >= (int)num.size()) {
              filled = 1;
              break;
            }
            num[p++] = num[i];
          }
          if (filled) break;
        }
      }
      len = ((len - l + MOD) * rep + l) % MOD;
    }
    cout << len << endl;
    ;
  }
  return 0;
}
