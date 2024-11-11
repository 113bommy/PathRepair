#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e+9 + 7;
const ll INF = LLONG_MAX;
const int N = (int)2e+5 + 8;
void MAIN(ll tc) {
  int n, k;
  cin >> n >> k;
  int arr[n + 1][n + 1];
  int num = n * n;
  for (int r = 1; r <= n; r++)
    for (int c = n; c >= k; c--) arr[r][c] = num--;
  for (int r = 1; r <= n; r++)
    for (int c = k - 1; c >= 1; c--) arr[r][c] = num--;
  int sum = 0;
  for (int r = 1; r <= n; r++) sum += arr[r][k];
  cout << sum << endl;
  for (int r = 1; r <= n; r++) {
    for (int c = 1; c <= n; c++) cout << arr[r][c] << ' ';
    cout << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  int test_cases = 1;
  for (int i = 1; i <= test_cases; i++) {
    MAIN(i);
  }
}
