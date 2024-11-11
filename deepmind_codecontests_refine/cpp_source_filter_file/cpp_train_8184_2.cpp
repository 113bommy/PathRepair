#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  while (cin >> n >> m >> k) {
    long long minN = 1 << 30;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      if (i % 2 == 0) minN = min(minN, v[i]);
    }
    if (n % 2 == 0 || n / 2 + 1 > m)
      cout << 0 << endl;
    else
      cout << min(minN, (m * k) / (n / 2 + 1)) << endl;
  }
  return 0;
}
