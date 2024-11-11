#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000007;
long long INFLL = (long long)INF * (long long)INF;
long double EPS = 10e-9;
long double pi = 2 * acos(0.0);
void solve() {
  long long n;
  cin >> n;
  if (n <= 2) {
    cout << n << "\n";
    return;
  }
  long long temp = n / 2;
  cout << (temp + 1ll) * (n + 1ll) / 2ll;
}
int32_t main() {
  clock_t start, end;
  start = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cerr << "\nTime taken by program is : " << fixed << time_taken
       << setprecision(5);
  cerr << " sec "
       << "\n";
  return 0;
}
