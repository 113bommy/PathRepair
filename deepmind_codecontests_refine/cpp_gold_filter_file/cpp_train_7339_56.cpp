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
void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
vector<vector<char> > a(8, vector<char>(8, '.'));
vector<long long> Min(8, LINF), Max(8, -LINF);
void Input() {
  for (long long i = 0; i < 8; i++) {
    for (long long j = 0; j < 8; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'W') Min[j] = min(Min[j], i);
      if (a[i][j] == 'B') Max[j] = max(Max[j], i);
    }
  }
}
void Solve() {
  long long A = LINF, B = LINF;
  for (long long i = 0; i < 8; i++) {
    bool Ablocked = false, Bblocked = false;
    for (long long j = 0; j < Min[i]; j++) {
      if (j > 7) break;
      Ablocked = (Ablocked | (a[j][i] == 'B'));
    }
    for (long long j = Max[i] + 1; j < 8; j++) {
      if (j < 0) break;
      Bblocked = (Bblocked | (a[j][i] == 'W'));
    }
    if (!Ablocked) A = min(A, Min[i]);
    if (!Bblocked) B = min(B, 7LL - Max[i]);
  }
  if (A <= B)
    cout << "A";
  else
    cout << "B";
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
