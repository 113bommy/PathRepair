#include <bits/stdc++.h>
using namespace std;
vector<bool> prime(1e6 + 5, true);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n), b(n);
  set<long long> x;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = m - 1; i >= 0; i--) {
    x.insert(a[i]);
    b[i] = x.size();
  }
  while (m--) {
    long long k;
    cin >> k;
    cout << b[k - 1] << "\n";
  }
  return 0;
}
