#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  vector<long long int> p(n + 1);
  p[0] = 0;
  for (long long int i = 1; i <= n; i++) {
    p[i] = p[i - 1] + a[i - 1];
  }
  for (long long int i = 0; i < m; i++) {
    long long int x;
    cin >> x;
    auto it = lower_bound(p.begin(), p.end(), x);
    long long int dorm = it - p.begin() + 1;
    x = x - p[dorm - 1];
    cout << dorm << " " << x << '\n';
  }
}
