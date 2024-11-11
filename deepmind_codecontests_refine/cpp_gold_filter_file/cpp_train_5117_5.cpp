#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using Pi_i = pair<int, int>;
using Pll_ll = pair<ll, ll>;
using VB = vector<bool>;
using VC = vector<char>;
using VD = vector<double>;
using VI = vector<int>;
using VLL = vector<ll>;
using VS = vector<string>;
using VSH = vector<short>;
using VULL = vector<ull>;
const int MOD = 1000000007;
const int INF = 1000000000;
const int NIL = -1;
const ll LINF = 1000000000000000000;
const double EPS = 1E-10;
template <class T, class S>
bool chmax(T &a, const S &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T, class S>
bool chmin(T &a, const S &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
int main() {
  string s;
  cin >> s;
  VI kind = {0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0,
             0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0};
  VB bekind(2, false);
  for (int i = (0), i_len = (s.length()); i < i_len; ++i) {
    bekind[kind[s[i] - 'A']] = true;
  }
  cout << ((bekind[0] ^ bekind[1]) ? "YES" : "NO");
  return 0;
}
