#include <bits/stdc++.h>
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
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
void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
long long p, d;
void Input() { cin >> p >> d; }
void Solve() {
  long long ans = LINF * 4, mul = 1, rem = 0;
  bool old = false;
  for (long long i = 1; i <= 18; i++) {
    mul *= 10;
    rem *= 10;
    rem += 9;
    long long z = p / mul;
    old = true;
    if (z > 0 && p - ((z - 1) * mul + rem) <= d &&
        p - ((z - 1) * mul + rem) >= 0) {
      if (old) {
        ans = (z - 1) * mul + rem;
        old = false;
      }
      ans = max(ans, (z - 1) * mul + rem);
    }
    if (p - ((z + 0) * mul + rem) <= d && p - ((z + 0) * mul + rem) >= 0) {
      if (old) {
        ans = (z + 0) * mul + rem;
        old = false;
      }
      ans = max(ans, (z + 0) * mul + rem);
    }
    if (p - ((z + 1) * mul + rem) <= d && p - ((z + 1) * mul + rem) >= 0) {
      if (old) {
        ans = (z + 1) * mul + rem;
        old = false;
      }
      ans = max(ans, (z + 1) * mul + rem);
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
