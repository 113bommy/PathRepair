#include <bits/stdc++.h>
using namespace std;
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << " = " << h << endl;
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << " = " << h << ", ";
  _dbg(sdbg + 1, a...);
}
const int maxn = (1e6) + 7;
const int maxk = 20;
const int inf = (1e9) + 7;
const long long LLinf = 10004205361450474LL;
const long double eps = 1e-9;
const long long mod = 1e9 + 7;
const long long M = 10000;
long long dp[maxn][10];
long long pd(long long a, long long b) { return dp[min(a, M)][b]; }
pair<long long, long long> ask(vector<long long> V) {
  cout << ((int)(V).size()) << " ";
  for (auto s : V) cout << s << " ";
  cout << endl;
  long long x;
  cin >> x;
  assert(x > -2);
  if (x == -1) exit(0);
  if (x == 0) return {1, V[0] - 1};
  if (x == ((int)(V).size())) return {V.back() + 1, LLinf};
  return {V[x - 1] + 1, V[x] - 1};
}
void solve(long long l, long long p, long long q) {
  ;
  assert(q > 0);
  long long dol = min(M, l);
  if (q == 1) {
    cout << dol << " ";
    for (long long i = 0; i < dol; i++) cout << l + i << " ";
    cout << endl;
    exit(0);
  }
  vector<long long> V;
  V.push_back(l + pd(l, q - 1) + 1);
  for (int i = 1; i < dol; i++)
    V.push_back(V.back() + 1 + pd(V.back() + 1, q - 1) + 1);
  pair<long long, long long> cur = ask(V);
  solve(max(l, cur.first), min(p, cur.second), q - 1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i <= M; i++) dp[i][1] = i - 1;
  for (int q = 2; q <= 5; q++)
    for (long long i = 0; i <= M; i++) {
      long long cur = i + dp[i][q - 1] + 1;
      for (int j = 0; j < i; j++) {
        cur = cur + 1 + dp[min(M, cur + 1)][q - 1] + 1;
        cur = min(cur, 2 * LLinf);
      }
      dp[i][q] = min(LLinf + 10, cur - i - 1);
    };
  solve(1, LLinf, 5);
  return 0;
}
