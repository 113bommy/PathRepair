#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
const int inf = 1e9 + 7;
void solve(int test) {
  int n, k;
  cin >> n;
  k = n / 2;
  cout << (k * (n - k)) << '\n';
  for (int i = 1; i <= k; i++) {
    for (int j = k + 1; j <= n; j++) {
      cout << i << ' ' << j << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
}
