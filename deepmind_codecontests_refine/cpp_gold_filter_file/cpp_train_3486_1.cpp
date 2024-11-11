#include <bits/stdc++.h>
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double PI = 3.141592653589793116, EPS = 1e-9,
                  GOLD = ((1 + sqrt(5)) / 2);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
vector<long long> HashMod(keymod, keymod + sizeof(keymod) / sizeof(long long));
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
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
auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();
long long n, m;
vector<string> a;
void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
void Input() {
  cin >> n >> m;
  a.resize(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
}
void Solve() {
  long long ans = 0;
  for (long long i = 0; i < n - 1; i++) {
    for (long long j = 0; j < m - 1; j++) {
      string z = "";
      z += a[i][j];
      z += a[i][j + 1];
      z += a[i + 1][j];
      z += a[i + 1][j + 1];
      sort(z.begin(), z.end());
      ans += (z == "acef");
    }
  }
  cout << ans;
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ControlIO(argc, argv);
  Input();
  TimerStart();
  Solve();
  TimerStop();
  return 0;
}
void ControlIO(int argc, char* argv[]) {}
void TimerStart() {}
void TimerStop() {}
void Exit() {
  TimerStop();
  exit(0);
}
