#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b, c, m;
  cin >> a >> b >> c >> m;
  if (m > a + b + c - 3) {
    cout << "NO" << endl;
    return;
  }
  vector<long long> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  sort(v.begin(), v.end());
  if (m + 1 >= v[2]) {
    cout << "YES" << endl;
    return;
  }
  v[2] = v[2] - m - 1;
  if (v[2] > (v[0] + v[1] + v[2]) / 2) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
