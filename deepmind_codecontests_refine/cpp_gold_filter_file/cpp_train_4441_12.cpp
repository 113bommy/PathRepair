#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
inline int nxt() {
  int x;
  scanf("%d", &x);
  return x;
}
inline long long lnxt() {
  long long x;
  scanf("%I64d", &x);
  return x;
}
const int base = (int)1e9;
const int N = (int)1e6 + 100;
const int MAXN = (int)1e3 + 100;
const int MOD = (int)1e9 + 7;
const int INF = INT_MAX;
const long long LL_INF = LLONG_MAX;
const long double PI = acos((long double)-1.0);
const long double EPS = 1e-8;
long long cnt = 0, ans = 0;
const int gto = (int)1e5 + 5;
vector<int> T(gto + 10), Num(gto + 10);
void solve() {
  int n = nxt();
  T[1] = 0;
  ++ans;
  for (int i = 2; i <= n; ++i) {
    int e;
    cin >> e;
    T[i] = T[e] + 1;
  }
  for (int i = 2; i <= n; ++i) {
    Num[T[i]]++;
  }
  for (int i = 1; i <= gto - 5; ++i) {
    ans += (Num[i] & 1);
  }
  printf("%lld", ans);
  ;
}
int main() {
  int T = 1;
  for (; T; --T) solve();
  return 0;
}
