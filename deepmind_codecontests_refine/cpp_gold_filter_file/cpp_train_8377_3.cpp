#include <bits/stdc++.h>
using namespace std;
const int INF = (int)2e9;
const long long INFL = (long long)9e18;
const int MAXINT = ((~0) ^ (1 << 31));
const long long MAXLL = ((~0) ^ ((long long)1 << 63));
template <class T>
inline T pow2(T a) {
  return a * a;
}
template <class T>
inline bool mineq(T& a, T b) {
  return (a > b) ? (a = b, true) : false;
}
template <class T>
inline bool maxeq(T& a, T b) {
  return (a < b) ? (a = b, true) : false;
}
const int maxn = (int)1e5 + 10;
;
string s1, s2, ans1, ans2;
int n, fans1 = 1, fans2 = 1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s1 >> s2;
  int l = -1, r = -1;
  for (int i = 0; i < (int)(n); i++) {
    if (s1[i] != s2[i]) {
      if (l == -1) l = i;
      r = i;
    }
  }
  if (l == r) {
    cout << 2;
    return 0;
  }
  for (int i = l; i < (int)(r); i++) {
    if (s1[i] != s2[i + 1]) fans1 = 0;
    if (s2[i] != s1[i + 1]) fans2 = 0;
  }
  if (fans1 + fans2 == 0) {
    cout << 0;
    return 0;
  }
  if (fans1 + fans2 == 1) {
    cout << 1;
    return 0;
  }
  s1.insert(s1.begin() + l, s2[l]);
  s2.insert(s2.begin() + r, s1[r + 1]);
  cout << (s1 == s2 ? 1 : 2);
}
