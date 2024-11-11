#include <bits/stdc++.h>
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
long long n;
vector<long long> A1, A2, B;
void Input() {
  cin >> n;
  A1.resize(n - 1);
  A2 = A1;
  B.resize(n);
  for (long long i = 0; i < n - 1; i++) cin >> A1[i];
  for (long long i = 0; i < n - 1; i++) cin >> A2[i];
  for (long long i = 0; i < n; i++) cin >> B[i];
}
void Solve() {
  priority_queue<long long, vector<long long>, greater<long long>> Q;
  for (long long i = 0; i < n; i++) {
    long long cnt = B[i];
    for (long long j = 0; j < i - 1; j++) cnt += A1[i];
    for (long long j = i; j < n - 1; j++) cnt += A2[i];
    Q.push(cnt);
  }
  long long ans = Q.top();
  Q.pop();
  ans += Q.top();
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
