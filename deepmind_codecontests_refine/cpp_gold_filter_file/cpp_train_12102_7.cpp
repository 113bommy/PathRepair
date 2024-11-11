#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long mod = 998244353;
void sol() {
  int n, k;
  cin >> n >> k;
  int a[n];
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  if (((int)(s).size()) > k) {
    cout << "-1";
    return;
  }
  int sum = 0;
  vector<int> b;
  cout << n * k << '\n';
  for (int i = 0; i < n; i++) {
    for (auto x : s) {
      cout << x << " ";
    }
    for (int j = 0; j < k - ((int)(s).size()); j++) cout << "1 ";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    sol();
    cout << '\n';
  }
  return 0;
}
