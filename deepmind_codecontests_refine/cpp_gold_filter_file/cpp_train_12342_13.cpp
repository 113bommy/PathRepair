#include <bits/stdc++.h>
#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9,
                  Gold = ((1 + sqrt(5)) / 2);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);
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
  return __builtin_popcountll(s);
}
auto TimeStart = chrono::steady_clock::now();
auto TimeEnd = chrono::steady_clock::now();
void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
long long a00, a01, a10, a11;
long long solve(long long z) {
  long long r = sqrt(2 * z);
  for (long long i = r - 4; i <= r + 4; i++) {
    if (i <= 0) continue;
    if (i * (i - 1) / 2 == z) return i;
  }
  return (-1);
}
void Input() { cin >> a00 >> a01 >> a10 >> a11; }
void Solve() {
  long long Zero = solve(a00), Ichi = solve(a11);
  if (Zero == -1 || Ichi == -1) {
    cout << "Impossible";
    return;
  }
  if (Zero == 1 && Ichi == 1) {
    if (a00 == 0 && a11 == 0 && a01 == 0 && a10 == 0)
      cout << "0";
    else if (a00 == 0 && a11 == 0 && a01 == 1 && a10 == 0)
      cout << "01";
    else if (a00 == 0 && a11 == 0 && a01 == 0 && a10 == 1)
      cout << "10";
    else
      cout << "Impossible";
    return;
  }
  if (Zero == 1 || Ichi == 1) {
    if (a01 == 0 && a10 == 0) {
      if (Zero != 1)
        for (long long i = 0; i < Zero; i++) cout << "0";
      else
        for (long long i = 0; i < Ichi; i++) cout << "1";
    } else if (a01 + a10 == max(Zero, Ichi)) {
      if (Zero < Ichi) {
        for (long long i = 0; i < a10; i++) cout << "1";
        cout << "0";
        for (long long i = 0; i < a01; i++) cout << "1";
      } else {
        for (long long i = 0; i < a01; i++) cout << "0";
        cout << "1";
        for (long long i = 0; i < a10; i++) cout << "0";
      }
    } else
      cout << "Impossible";
    return;
  }
  if (a01 + a10 != Zero * Ichi) {
    cout << "Impossible";
    return;
  }
  vector<long long> cnt(Zero + 1, 0LL);
  for (long long i = 0; i < Ichi; i++) {
    if (a01 < a10) {
      long long id = 0;
      if (a10 < Zero) id = Zero - a10;
      cnt[id]++;
      a01 -= id;
      a10 -= (Zero - id);
    } else {
      long long id = Zero;
      if (a01 < Zero) id = a01;
      cnt[id]++;
      a01 -= id;
      a10 -= (Zero - id);
    }
  }
  for (long long x = 0; x <= Zero; x++) {
    for (long long z = 0; z < cnt[x]; z++) cout << "1";
    if (x != Zero) cout << "0";
  }
}
int main(int argc, char* argv[]) {
  ControlIO(argc, argv);
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
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
