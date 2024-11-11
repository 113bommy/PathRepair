#include <bits/stdc++.h>
const int MX[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int MY[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int MXX[] = {-1, 0, 1, 0};
const int MYY[] = {0, 1, 0, -1};
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long k, b, n, t, z, i, j, tc = 3, count;
  while (tc--) {
    cin >> k >> b >> n >> t;
    count = 1;
    while (count <= t) {
      count = count * k + b;
      --n;
    }
    i = max(0LL, n + 1);
    cout << i << endl;
  }
  return 0;
}
