#include <bits/stdc++.h>
using namespace std;
int add(int a, int b) {
  return (a % 1000000007 + b % 1000000007 +
          ((8000000000000000064ll) / 1000000007) * 1000000007) %
         1000000007;
}
int sub(int a, int b) {
  return (a % 1000000007 - b % 1000000007 +
          ((8000000000000000064ll) / 1000000007) * 1000000007) %
         1000000007;
}
int mul(int a, int b) {
  return ((a % 1000000007) * (b % 1000000007) +
          ((8000000000000000064ll) / 1000000007) * 1000000007) %
         1000000007;
}
vector<int> in(int n) {
  vector<int> v1;
  v1.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v1[i];
  }
  return v1;
}
void go() {
  int n;
  cin >> n;
  int mx = ceil((n + 2) / 2);
  cout << mx << "\n";
  for (int i = 1, j = 1; j <= min(n, mx); j++) cout << i << " " << j << "\n";
  int c = n - mx;
  if (c > 0) {
    int x = mx + c;
    int i = mx, j = mx - c + 1;
    while (c--) cout << i << " " << j << "\n", j++;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  go();
}
