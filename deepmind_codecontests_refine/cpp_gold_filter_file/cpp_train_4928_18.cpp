#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, n;
  cin >> n >> a >> b;
  int aa[100009] = {};
  for (int i = 0; i < n; i++) cin >> aa[i];
  sort(aa, aa + n);
  cout << aa[n - a] - aa[n - a - 1];
  return 0;
}
