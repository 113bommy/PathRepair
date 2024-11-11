#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return (!b) ? a : gcd(b, a % b);
}
int n, k;
int p[8][8];
int a[8];
int p10(int k) {
  int temp = 1;
  for (int i = 1; i <= k; i++) temp *= 10;
  return temp;
}
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k - 1; j++) {
      char c;
      cin >> c;
      p[i][j] = c - '0';
    }
  }
  for (int i = 0; i <= k - 1; i++) {
    a[i] = i;
  }
  int ans = 1e8;
  do {
    int minv = 1e8;
    int maxv = 0;
    for (int i = 1; i <= n; i++) {
      int cur = 0;
      for (int j = 0; j <= k - 1; j++) {
        cur += p10(a[j]) * p[i][j];
      }
      minv = min(minv, cur);
      maxv = max(maxv, cur);
    }
    ans = min(ans, maxv - minv);
  } while (next_permutation(a, a + k));
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  int t = 1;
  while (t--) {
    solve();
  }
}
