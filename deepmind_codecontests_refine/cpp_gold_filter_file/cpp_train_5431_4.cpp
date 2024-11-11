#include <bits/stdc++.h>
using namespace std;
long long int check(long long int n) {
  long long int ans = 0;
  while (n) {
    ans += n % 10;
    n /= 10;
  }
  return (4 - ans % 4) % 4;
}
void solve() {
  long long int n;
  cin >> n;
  vector<long double> v(n);
  vector<long long int> a;
  long long int sum = 0;
  for (__typeof(n) i = 0; i < n; i++) {
    cin >> v[i];
    a.emplace_back(v[i]);
    sum += a[i];
  }
  if (sum > 0) {
    for (__typeof(n) i = 0; i < n; i++) {
      if (a[i] != v[i] && v[i] < 0) {
        a[i]--;
        sum--;
      }
      if (sum == 0) break;
    }
  }
  if (sum < 0) {
    for (__typeof(n) i = 0; i < n; i++) {
      if (a[i] != v[i] && v[i] > 0) {
        a[i]++;
        sum++;
      }
      if (sum == 0) break;
    }
  }
  if (sum == 0) {
    for (__typeof(n) i = 0; i < n; i++) cout << a[i] << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
