#include <bits/stdc++.h>
using namespace std;
long long t, n, k;
long long base[12] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    map<long long, long long> f;
    for (int i = 1; i <= n; ++i) {
      cin >> k;
      f[k] += 1;
    }
    for (int i = 0; i <= 10; ++i) f[base[i + 1]] += f[base[i]] / 2;
    if (f[2048] >= 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
