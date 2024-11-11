#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
void solve() {
  int sum = 0, d, n;
  cin >> d >> n;
  for (int i = 0; i < n - 1; i++) {
    int k;
    cin >> k;
    sum = sum + d - k;
  }
  cout << sum;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
