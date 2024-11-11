#include <bits/stdc++.h>
using namespace std;
const int N = 1000000007;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int a[2], d[2];
  a[1] = 1, d[1] = 0;
  for (int x = 2; x <= n; x++) {
    a[x % 2] = (2 * a[(x - 1) % 2] + d[(x - 1) % 2]) % N;
    d[x % 2] = (3 * a[(x - 1) % 2]) % N;
  }
  cout << d[n % 2];
  return 0;
}
