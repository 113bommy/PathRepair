#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  long long int sum = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  vector<long long int> v2;
  long long int count = n - 1;
  for (long long int i = 0; i < n; i++) {
    long long int k = sum;
    k -= v[i];
    if (k % count == 0 && k / count == v[i]) {
      v2.push_back(v[i]);
    }
  }
  if (v2.size() == 0) {
    cout << "0" << endl;
    return;
  }
  sort(v2.begin(), v2.end());
  cout << v2.size() << endl;
  for (auto x : v2) {
    cout << x << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int t = 1;
  while (t--) {
    solve();
  }
}
