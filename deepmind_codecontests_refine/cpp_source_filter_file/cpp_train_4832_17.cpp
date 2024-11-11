#include <bits/stdc++.h>
#pragma comment(linker, "/stack:225450978")
#pragma GCC optimize("Ofast")
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
string cppstr_infile = "FILE.IN";
string cppstr_outfile = "FILE.OUT";
long long n, k;
vector<long long> a, s(1000001, 0);
long long Query(long long L, long long R) {
  long long res = s[R];
  if (L > 0) res -= s[L - 1];
  return res;
}
void Input() {
  cin >> n >> k;
  a.resize(n);
  for (auto& x : a) {
    cin >> x;
    s[x]++;
  }
}
void Solve() {
  for (long long i = 1; i < 1000001; i++) s[i] += s[i - 1];
  long long ans = min(k, *min_element(a.begin(), a.end()));
  for (long long d = 1; d < 1000001; d++) {
    long long cnt = 0;
    for (long long i = d; i < 1000001; i += d) {
      long long j = min(i + k, 1000000LL);
      cnt += Query(i, j);
    }
    if (cnt == n) ans = d;
  }
  cout << ans << '\n';
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
void ControlIO(int argc, char* argv[]) {
  char* infile = new char[cppstr_infile.size() + 1];
  char* outfile = new char[cppstr_outfile.size() + 1];
  strcpy(infile, cppstr_infile.c_str());
  strcpy(outfile, cppstr_outfile.c_str());
}
void TimerStart() {}
void TimerStop() {}
void Exit() {
  TimerStop();
  exit(0);
}
