#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, n, a, b, x[2010];
  cin >> n >> a >> b;
  for (i = 0; i < n; i++) cin >> x[i];
  sort(x, x + n);
  cout << x[b] - x[b - 1] << endl;
  return 0;
}
