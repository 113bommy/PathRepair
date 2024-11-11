#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long mod = 1000000007;
int a[111][111];
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int g = 0, x;
    for (int j = 0; j < n; j++) {
      cin >> x;
      if (x != -1) g = g | x;
    }
    cout << g << " ";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
