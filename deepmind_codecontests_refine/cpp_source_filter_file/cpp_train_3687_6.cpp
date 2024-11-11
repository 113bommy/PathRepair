#include <bits/stdc++.h>
using namespace std;
int n, k, a[200001], minn = 99999, d = -1, b[900001], g;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i % k == 0)
      g = k;
    else
      g = i % k;
    b[g] += a[i];
  }
  for (int i = 1; i <= k; i++)
    if (b[i] < minn) minn = b[i], d = i;
  cout << d << endl;
  return 0;
}
