#include <bits/stdc++.h>
using namespace std;
typedef set<int, bool (*)(int, int)> sic;
typedef set<pair<int, int>, bool (*)(pair<int, int>, pair<int, int>)> spic;
typedef set<long long int, bool (*)(long long int, long long int)> slc;
typedef set<pair<long long int, long long int>,
            bool (*)(pair<long long int, long long int>,
                     pair<long long int, long long int>)>
    splc;
pair<int, int> operator+(const pair<int, int>& x, const pair<int, int>& y) {
  return {x.first + y.first, x.second + y.second};
}
pair<long long int, long long int> operator+(
    const pair<long long int, long long int>& x,
    const pair<long long int, long long int>& y) {
  return {x.first + y.first, x.second + y.second};
}
long long int gcd(long long int a, long long int b) {
  return a >= b ? b ? gcd(b, a % b) : a : gcd(b, a);
}
long long int lcm(long long int a, long long int b) {
  return a / gcd(a, b) * b;
}
long long int exp(long long int a, long long int b) {
  long long int r = 1;
  while (b)
    r = (1000000007LL +
         ((long long int)(r) * (long long int)(b & 1 ? a : 1)) % 1000000007LL) %
        1000000007LL,
    a = (1000000007LL +
         ((long long int)(a) * (long long int)(a)) % 1000000007LL) %
        1000000007LL,
    b >>= 1;
  return r;
}
long long int fac[500000];
long long int ifac[500000];
void mkfac() {
  fac[0] = ifac[0] = 1;
  for (int i = (int)(!0); i <= (int)(500000 - 1 - 0); i++)
    fac[i] =
        (1000000007LL +
         ((long long int)(fac[i - 1]) * (long long int)(i)) % 1000000007LL) %
        1000000007LL,
    ifac[i] = exp((fac[i]), 1000000007LL - 2);
}
string out;
long long int T;
unordered_set<int> adj[500000];
long long int DP[500000][3];
long long int A[500000];
int N, M, K;
long long int u, v;
string S;
void process() {
  cin >> N >> M;
  for (int i = (int)(!0); i <= (int)(N - 0); i++) cin >> A[i];
  for (int i = (int)(!0); i <= (int)(N - 0); i++) {
    DP[i][0] = max(0LL, DP[i - 1][0]) + A[i];
    DP[i][1] = max(0LL, max(DP[i - 1][0], DP[i - 1][1])) + M * A[i];
    DP[i][2] = max(0LL, max(DP[i - 1][1], DP[i - 1][0])) + A[i];
    v = max(v, max(DP[i][0], max(DP[i][1], DP[i][2])));
  }
  out += to_string(v), out += "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  T = 1;
  for (int t = (int)(!0); t <= (int)(T - 0); t++) process();
  cout << out;
  return 0;
}
