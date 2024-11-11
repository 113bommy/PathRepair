#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lld = long double;
using vi = vector<int>;
using vll = vector<long long>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  for (int &u : a) {
    cin >> u;
  }
  int m = 1e9;
  int ans = 1e9;
  for (int i = 1; i < n; i++) {
    m = min(m, min(a[i - 1], a[n - i]));
    ans = min(ans, m / (n - i));
  }
  cout << ans;
}
