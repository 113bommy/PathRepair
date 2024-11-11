#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, r[1000], c[1000], min[1000], sum = 0;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> r[i] >> c[i];
    min[i] = 9999999999;
  }
  for (int i = 0; i < n; i++)
    if (min[r[i] - 1] > c[i]) min[r[i] - 1] = c[i];
  for (int i = 0; i < m; i++) sum += min[i];
  if (sum > k)
    cout << k;
  else
    cout << sum;
}
