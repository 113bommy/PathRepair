#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
const long long BIG = 1446803456761533460LL;
const int Big = 336860180;
const long long int INF = LONG_LONG_MAX;
const long long int adj4[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const long long int adj8[8][2] = {{0, 1},   {0, -1}, {1, 0},  {-1, 0},
                                  {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
long long int clk_ar[10];
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long int powMod(long long int a, long long int b) {
  long long int n = 1;
  long long int p = a;
  while (b > 0) {
    if (b % 2 == 1) {
      n *= p;
      n %= MOD;
    }
    p *= p;
    p %= MOD;
    b /= 2;
  }
  return n;
}
long long int modularInverse(long long int a) { return powMod(a, MOD - 2); }
stringstream sss;
const long long int maxn = 110;
const long long int T = 20000;
long long int state[maxn];
long long int ai[maxn];
long long int bi[maxn];
void MAIN() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  for (long long int i = 0; i < (n); ++i) {
    state[i] = s[i] == '1';
  }
  for (long long int i = 0; i < (n); ++i) {
    cin >> ai[i] >> bi[i];
  }
  long long int mx = count(state, state + n, 1);
  for (long long int t = 0; t < (T); ++t) {
    for (long long int i = 0; i < (n); ++i) {
      if (t > bi[i] && (t - bi[i]) % ai[i] == 0) {
        state[i] ^= 1;
      }
    }
    mx = max(mx, ((long long int)count(state, state + n, 1)));
  }
  cout << (mx) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  sss << R"(
6
011100
5 3
5 5
2 4
3 5
4 2
1 5
    )";
  MAIN();
  return 0;
}
