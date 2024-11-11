#include <bits/stdc++.h>
const int INF = (int)1e9;
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  double discriminant = 2.25 + 2.0 * (n + k);
  int x = sqrt(discriminant) - 1.5;
  cout << n - x << '\n';
  return 0;
}
