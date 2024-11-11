#include <bits/stdc++.h>
using namespace std;
long long int n, m, k, i, s, ma, mi, x[200001], l, p;
int main() {
  cin >> n >> m >> k;
  for (i = 0; i < n; i++) cin >> x[i];
  sort(x, x + n);
  ma = x[n - 1];
  mi = x[n - 2];
  p = ma * k + mi;
  if (m == k)
    cout << ma * k << endl;
  else {
    l = m / (k + 1);
    s += p * l;
    s += ma * (m - l * (k + 1));
  }
  cout << s << endl;
}
