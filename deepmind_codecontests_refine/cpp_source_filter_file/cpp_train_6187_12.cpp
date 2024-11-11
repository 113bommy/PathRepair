#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (!n) {
    cout << 1 << endl;
    return 0;
  }
  long long m = n;
  long long res = n;
  for (int i = 1; i <= n; i++) {
    long long u = m;
    while (u * u + i * i > n * n) u--;
    res += max(0LL, m - u - 1);
    m = u;
  }
  cout << res * 4 << endl;
  return 0;
}
