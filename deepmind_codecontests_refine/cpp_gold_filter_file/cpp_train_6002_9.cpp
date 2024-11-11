#include <bits/stdc++.h>
using namespace std;
long long ans, i, j, n, k, l, z, m;
map<long long, long long> mp;
int main() {
  cin >> n >> m;
  z = (n * (n + 1)) / 2;
  i = 0;
  while (m >= 0) {
    i++;
    m = m - i;
    if (i == n && m > 0) {
      i = 0;
    }
  }
  cout << m + i;
  return 0;
}
