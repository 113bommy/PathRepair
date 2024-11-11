#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long p = 1000000;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  long long a[n];
  if (n % 2 == 0) {
    return cout << 0, 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2 == 0) {
      p = min(a[i], p);
    }
  }
  cout << min(p, k * m / ((n + 1) / 2));
}
