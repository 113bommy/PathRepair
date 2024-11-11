#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> vals(n);
  for (int i = 0; i < n; i++) cin >> vals[i];
  if (n == 1)
    cout << min(vals[0], k * m) << "\n";
  else if (m < (n + 1) / 2 || n % 2 == 0)
    cout << 0 << "\n";
  else {
    long long cmi = vals[0];
    for (int i = 0; i < n; i++)
      if (i % 2 == 0) cmi = min(cmi, vals[i]);
    cout << min(cmi, k * (m / ((n + 1) / 2))) << "\n";
  }
  return 0;
}
