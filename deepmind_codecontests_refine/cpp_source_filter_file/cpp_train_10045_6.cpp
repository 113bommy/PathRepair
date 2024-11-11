#include <bits/stdc++.h>
using namespace std;
long long n, m, first[100001];
int main() {
  cin >> n >> m;
  first[1] = first[0] = 1;
  for (int k = 2; k <= n; ++k) first[k] = first[k - 1] + first[k - 2];
  for (int k = 1; k <= n; k) {
    if (first[n - k] >= m) {
      cout << k << ' ';
      k += 1;
      continue;
    }
    cout << k + 1 << ' ' << k << ' ';
    m -= first[n - k + 1];
    k += 2;
  }
  return 0;
}
