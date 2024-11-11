#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  std::vector<long long int> v(n);
  long long int sum = 0;
  for (long long int i = 0; i < n; ++i) {
    cin >> v[i];
    sum += v[i];
    v[i] = sum;
  }
  long long int m;
  cin >> m;
  for (long long int i = 0; i < m; ++i) {
    long long int no;
    cin >> no;
    cout << (lower_bound(v.begin(), v.end(), no) - v.begin()) + 1;
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
