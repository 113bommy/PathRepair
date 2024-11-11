#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000007;
long long INFLL = (long long)INF * (long long)INF;
long double EPS = 10e-9;
long double pi = 2 * acos(0.0);
long long mod = 1e9 + 7;
long long sum = 0ll;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long s[n];
  long long sum = 0;
  for (long long i = 0; i < n; ++i) {
    cin >> s[i];
    sum += s[i];
  }
  if (n < k || sum % k > 0) {
    cout << "No"
         << "\n";
    return;
  }
  long long need = sum / k;
  vector<long long> ans;
  for (long long i = 0; i < n; ++i) {
    long long temp = 0;
    long long j = i;
    while (temp < need and i < n) {
      temp += s[i];
      i++;
    }
    if (temp != need) {
      cout << "No"
           << "\n";
      return;
    }
    i--;
    ans.push_back(i - j + 1);
  }
  if (ans.size() != k) {
    cout << "No"
         << "\n";
    return;
  }
  cout << "Yes"
       << "\n";
  for (auto ash : ans) {
    cout << ash << " ";
  }
}
int32_t main() {
  clock_t start, end;
  start = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  while (tc--) solve();
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cerr << "\nTime taken by program is : " << fixed << time_taken
       << setprecision(5);
  cerr << " sec "
       << "\n";
  return 0;
}
