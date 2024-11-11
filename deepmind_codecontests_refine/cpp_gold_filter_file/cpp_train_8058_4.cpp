#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long a[n + 5], b[n + 5];
  set<long long> s;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = n; i >= 1; i--) {
    s.insert(a[i]);
    b[i] = s.size();
  }
  long long x;
  for (int i = 0; i < m; i++) {
    cin >> x;
    cout << b[x] << "\n";
  }
  return 0;
}
