#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int cl(int x, int y) { return (x / y) + (x % y != 0); }
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  int sum = 0, cur = v[0];
  for (int i = 0; i < n; i++) {
    if (v[i] < sum) {
      cout << "NO\n";
      return;
    }
    v[i] -= sum;
    if (v[i] < cur) {
      cur = v[i];
    }
    if (v[i] > cur) {
      sum += v[i] - cur;
    }
  }
  cout << "YES" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
