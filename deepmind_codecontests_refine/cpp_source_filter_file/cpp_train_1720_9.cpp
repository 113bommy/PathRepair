#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
const long double PI = 3.14159265358979323846;
const long long MOD = 1e+9 + 7;
const long long INF = LLONG_MAX;
const int INFi = INT_MAX;
const long long N = 2e+5 + 8;
vector<long long> adj[N];
long long vis[N];
long long dx4[] = {0, 1, 0, -1}, dy4[] = {1, 0, -1, 0};
long long test_cases = 1;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
;
long long n, a[N];
void MAIN(long long tc) {
  cin >> n;
  for (long long i = (0); i <= 1e7; i++) {
    if ((i * (i + 1) / 2) >= n) {
      n -= i * (i - 1) / 2;
      cout << n << " ";
      cout << "\n";
      ;
      ;
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  ;
  for (long long i = (1); i <= test_cases; i++) {
    MAIN(i);
  }
}
