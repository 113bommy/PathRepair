#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
ll INF = LLONG_MAX;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
namespace output {
void pr(int x) { cout << x; }
void pr(long x) { cout << x; }
void pr(ll x) { cout << x; }
void pr(unsigned x) { cout << x; }
void pr(unsigned long x) { cout << x; }
void pr(unsigned long long x) { cout << x; }
void pr(float x) { cout << x; }
void pr(double x) { cout << x; }
void pr(ld x) { cout << x; }
void pr(char x) { cout << x; }
void pr(const char* x) { cout << x; }
void pr(const string& x) { cout << x; }
void pr(bool x) { pr(x ? "true" : "false"); }
template <class T>
void pr(const complex<T>& x) {
  cout << x;
}
template <class T1, class T2>
void pr(const pair<T1, T2>& x);
template <class T>
void pr(const T& x);
template <class T, class... Ts>
void pr(const T& t, const Ts&... ts) {
  pr(t);
  pr(ts...);
}
template <class T1, class T2>
void pr(const pair<T1, T2>& x) {
  pr("{", x.f, ", ", x.s, "}");
}
template <class T>
void pr(const T& x) {
  pr("{");
  bool fst = 1;
  for (const auto& a : x) pr(!fst ? ", " : "", a), fst = 0;
  pr("}");
}
void print() { pr("\n"); }
template <class T, class... Ts>
void print(const T& t, const Ts&... ts) {
  pr(t);
  if (sizeof...(ts)) pr(" ");
  print(ts...);
}
}  // namespace output
using namespace output;
bool query(int pos) {
  cout << "? " << pos + 1 << endl;
  fflush(stdout);
  char ans;
  cin >> ans;
  return ans == 'Y';
}
void reset() {
  cout << "R" << endl;
  fflush(stdout);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int N, K;
  cin >> N >> K;
  int ans = 0;
  vector<bool> seen(N);
  if (K > 1) K /= 2;
  for (int g = K; g < N; g += K) {
    for (int l = 0; l < g; l += K) {
      for (int i = (l); i < (l + K); ++i) seen[i] = seen[i] | query(i);
      for (int r = l + g; r + K <= N; r += g) {
        for (int i = (r); i < (r + K); ++i) seen[i] = seen[i] | query(i);
      }
      reset();
    }
  }
  for (int i = (0); i < (N); ++i) ans += !seen[i];
  cout << "! " << ans << endl;
  fflush(stdout);
}
