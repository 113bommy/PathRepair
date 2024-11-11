#include <bits/stdc++.h>
long long cnt;
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> f(n), s(n);
  for (long long i = 0; i < n; i++) {
    cin >> f[i];
    cin >> s[i];
  }
  long long mn = *min_element(f.begin(), f.end());
  long long mx = *max_element(s.begin(), s.end());
  long long i = 0;
  for (long long i = 0; i < n; i++) {
    if (f[i] == mn and s[i] == mx) {
      cout << i + 1;
      return;
    }
    i++;
  }
  cout << -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
