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
const int MAX_D = 502, MAX_S = 5020;
int D, S;
bool Vst[MAX_D][MAX_S];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << std::setprecision(10);
  cout << fixed;
  cin >> D >> S;
  queue<pair<pair<int, int>, string>> q;
  for (int i = 1; i <= 9; i++) {
    pair<int, int> ds(i % D, i);
    string s(1, '0' + i);
    q.emplace(ds, s);
    Vst[i % D][i] = 1;
    if (i % D == 0 && i == S) {
      cout << s << endl;
      return 0;
    }
  }
  while (!q.empty()) {
    auto [d, s] = q.front().first;
    string st = q.front().second;
    q.pop();
    int doff = d * 10 % D;
    for (int i = 0; i <= 9; i++) {
      int news = s + i;
      int newd = (doff + i) % D;
      if (news > S) continue;
      if (newd == 0 && news == S) {
        cout << st << i << endl;
        return 0;
      }
      if (Vst[newd][news]) continue;
      Vst[newd][news] = 1;
      string newst(1, '0' + i);
      q.emplace(make_pair(newd, news), st + newst);
    }
  }
  cout << -1 << endl;
  return 0;
}
