#include <bits/stdc++.h>
using namespace std;
clock_t time_p = clock();
void Time() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
const int INF = 1e9;
const long long INF64 = 9e18;
const long long mod = 998244353;
int modo(long long n) { return (n % mod); }
void solve() {
  int n;
  cin >> n;
  vector<long long> pwr(n + 1, 0);
  pwr[0] = 1;
  for (long long i = 1; i <= n; ++i) {
    pwr[i] = modo(pwr[i - 1] * 10);
  }
  for (int i = 1; i < n; ++i) {
    long long ans;
    if (n - i - 1 >= 0) ans = 2 * 10 * 9 * pwr[n - i - 1];
    if (n - i - 2 >= 0) ans += 9 * 9 * pwr[n - i - 2] * 10 * (n - i - 1);
    cout << modo(ans) << " ";
  }
  cout << 10 << endl;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(35);
  int t;
  solve();
  Time();
  return 0;
}
