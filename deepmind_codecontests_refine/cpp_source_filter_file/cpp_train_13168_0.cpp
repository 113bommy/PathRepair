#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9,
                  GOLD = ((1 + sqrt(5)) / 2);
vector<long long> HashMod = {1000000007LL, 1000000009LL, 1000000021LL,
                             1000000033LL};
template <class T>
int getbit(T s, int i) {
  return (s >> 1) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcount(s);
}
long long n, s;
map<long long, long long> MapB, MapS;
char d;
long long p, q;
void VarInput() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> s;
  while (n--) {
    cin >> d >> p >> q;
    if (d == 'B')
      MapB[-p] += q;
    else
      MapS[-p] += q;
  }
}
void ProSolve() {
  long long tmp = MapS.size();
  for (auto it = MapS.begin(); it != MapS.end(); it++) {
    tmp--;
    if (tmp > s) continue;
    cout << "S " << -(it->first) << " " << (it->second) << '\n';
    tmp--;
  }
  tmp = s;
  for (auto it = MapB.begin(); it != MapB.end(); it++) {
    if (tmp <= 0) break;
    cout << "B " << -(it->first) << " " << (it->second) << '\n';
    tmp--;
  }
}
int main() {
  VarInput();
  ProSolve();
  return 0;
}
