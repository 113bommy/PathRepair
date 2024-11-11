#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const int N = 100005;
long long int a[N], b[N];
multiset<long long int> x, y;
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long int n;
  cin >> n;
  for (long long int i = 1; i <= n; i++) cin >> a[i];
  for (long long int i = 1; i <= n; i++) cin >> b[i];
  for (long long int i = 1; i < n; i++) {
    x.insert(a[i + 1] - a[i]);
    y.insert(b[i + 1] - b[i]);
  }
  if (a[1] == b[1] && a[n] == b[n] && x == y)
    cout << "Yes" << '\n';
  else
    cout << "No" << '\n';
}
