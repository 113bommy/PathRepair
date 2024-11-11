#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-9;
int n, a[100500];
int b[10];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
  }
  if (b[7] || b[5]) {
    puts("-1");
    return 0;
  }
  int k1, k2, k3, k4;
  k3 = b[3];
  k1 = b[4];
  k2 = b[6] - b[3];
  if (k1 + k2 + k3 != a[1] || k2 + k1 != a[2] || k3 != b[3] || k1 != b[4] ||
      k2 + k3 != b[6]) {
    puts("-1");
    return 0;
  }
  if (3 * (k1 + k2 + k3) == n && k1 >= 0 && k2 >= 0 && k3 >= 0) {
    for (int i = 0; i < k1; i++) cout << "1 2 4\n";
    for (int i = 0; i < k2; i++) cout << "1 2 6\n";
    for (int i = 0; i < k3; i++) cout << "1 3 6\n";
    return 0;
  }
  puts("-1");
  return 0;
}
