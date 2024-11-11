#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e7 + 1;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v(39, 0);
  vector<long long int> v1(39, 0);
  v[0] = 1;
  v1[0] = 1;
  for (long long int i = 1; i < 39; i++) v[i] = v[i - 1] * 3;
  for (long long int i = 1; i < 39; i++) v1[i] = v1[i - 1] + v[i];
  long long int a1 = lower_bound(v1.begin(), v1.end(), n) - v1.begin();
  long long int a2 = v1[a1];
  for (long long int i = a1; i >= 0; i--) {
    if (a2 - v[i] >= n) a2 -= v[i];
  }
  cout << a2 << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
