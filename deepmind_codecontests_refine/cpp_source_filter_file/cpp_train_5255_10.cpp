#include <bits/stdc++.h>
using namespace std;
int w[109][109], n, m;
long long a[109], b[109], k1 = 0, k2 = 0, e;
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> w[i][j];
  a[0] = 0;
  for (int i = 0; i < m; i++) b[i] = w[0][i];
  for (int i = 0; i < n; i++) a[i] = w[i][0] - b[0];
  bool flag = false;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      e = w[i][j] - a[i] - b[j];
      k1 = max(k1, (long long)w[i][j]);
      k2 = gcd(e, k2);
    }
  if (k2 == 0) {
    k1++;
    cout << "YES\n";
    cout << k1 << endl;
    for (int i = 0; i < n; i++) cout << (a[i] % k1) + k1 << " ";
    cout << endl;
    for (int i = 0; i < m; i++) cout << (b[i] % k1) + k1 << " ";
  } else if (k2 > k1) {
    cout << "YES\n";
    cout << k2 << endl;
    for (int i = 0; i < n; i++) cout << (a[i] % k2) + k2 << " ";
    cout << endl;
    for (int i = 0; i < m; i++) cout << (b[i] % k2) + k2 << " ";
  } else {
    cout << "NO";
  }
}
