#include <bits/stdc++.h>
using namespace std;
long long const INF = 1e16;
long long power(long long a, long long b) {
  long long result = 1;
  while (b) {
    if (b % 2) result = (result * a) % 1000000007;
    a = (a * a) % 1000000007;
    b /= 2;
  }
  return result;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort((a).begin(), (a).end());
  int r = n / 2;
  for (int i = 1; i <= r; i++) {
    cout << a[i] << " " << a[r] << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    solve();
  }
  return 0;
}
