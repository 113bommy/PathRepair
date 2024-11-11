#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int n, long long int p) {
  long long int result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result % p * x % p) % p;
    x = (x % p * x % p) % p;
    n = n / 2;
  }
  return result % p;
}
bool compare(pair<long long int, long long int> a1,
             pair<long long int, long long int> a2) {
  return (a1.first >= a2.first);
}
void solve() {
  long long int n;
  cin >> n;
  vector<pair<long long int, long long int>> v1(n);
  for (long long int i = 0; i <= n - 1; i++) {
    cin >> v1[i].first;
    v1[i].second = i + 1;
  }
  sort(v1.begin(), v1.end(), compare);
  long long int ans = 0;
  long long int x = 0;
  for (long long int i = 0; i <= n - 1; i++) {
    ans += (x * v1[i].first) + 1;
    x++;
  }
  cout << ans << endl;
  for (long long int i = 0; i <= n - 1; i++) {
    cout << v1[i].second << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    solve();
  }
}
