#include <bits/stdc++.h>
using namespace std;
bool com(pair<int, int> x, pair<int, int> y) {
  if (x.first == y.first) return x.second < y.second;
  return x.first < y.first;
}
long long int power(long long int x, long long int y) {
  long long int prod = 1;
  while (y) {
    if (y & 1) prod = (prod * x) % 1000000007;
    x = (x * x) % 1000000007;
    y /= 2;
  }
  return prod;
}
const int N = 2e5 + 7;
int tc = 1;
void solve() {
  int n;
  cin >> n;
  vector<int> ans(n + 1);
  ans[n] = n;
  for (int i = n; i > 1; i--) {
    cout << "? ";
    for (int j = 1; j < n; j++) {
      cout << 1 << " ";
    }
    cout << i << endl;
    int x;
    cin >> x;
    if (x == 0) continue;
    ans[n] = n + 1 - i;
    break;
  }
  for (int i = n; i > 0; i--) {
    if (ans[n] == i) continue;
    cout << "? ";
    for (int j = 1; j < n; j++) {
      cout << n << " ";
    }
    cout << n + i - ans[n] << endl;
    int x;
    cin >> x;
    ans[x] = i;
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
