#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9,
                  GOLD = ((1 + sqrt(5)) / 2);
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
long long Q, L, R;
set<long long> sadpowers;
vector<long long> SadPowers;
long long prime[18] = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                       29, 31, 37, 41, 43, 47, 53, 59, 61};
bool isSquare(long long z) {
  long long zx = sqrt(z);
  return (zx * zx == z);
}
void VarInput() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  for (long long i = 3; i < 63; i++) {
    bool flag = true;
    for (long long j = 0; j <= 1000000; j++) {
      long long zazz = 1;
      for (long long k = 0; k < i; k++) {
        if (j > 0 && 3 * LINF / j < zazz) {
          flag = false;
          break;
        }
        zazz *= j;
      }
      if (!flag) break;
      if (isSquare(zazz)) continue;
      if (sadpowers.find(zazz) == sadpowers.end()) sadpowers.insert(zazz);
    }
  }
  for (auto it = sadpowers.begin(); it != sadpowers.end(); it++)
    SadPowers.push_back(*it);
  cin >> Q;
}
void ProSolve() {
  while (Q--) {
    L = 1;
    cin >> R;
    long long ans = floor(sqrtl(R)) - ceil(sqrtl(L)) + 1;
    long long st =
        lower_bound(SadPowers.begin(), SadPowers.end(), L) - SadPowers.begin();
    long long en =
        upper_bound(SadPowers.begin(), SadPowers.end(), R) - SadPowers.begin();
    ans += (en - st);
    cout << ans << '\n';
  }
}
int main() {
  VarInput();
  ProSolve();
  return 0;
}
