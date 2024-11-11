#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, l;
  cin >> n >> m >> k >> l;
  if (m > n || l + k > n) return cout << -1, 0;
  if ((l + k + m - 1) / m * m > n)
    cout << -1;
  else
    (l + k + m - 1) / m;
}
