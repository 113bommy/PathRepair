#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, a, b, w[100000], x, z;
  cin >> n >> a >> b;
  for (i = 0; i < n; i++) cin >> w[i];
  for (i = 0; i < n; i++) {
    x = (a * w[i]) / b;
    z = (b * x) / a;
    if ((b * x) % a == 0)
      cout << w[i] - z << " ";
    else
      cout << w[i] - z - 1 << " ";
  }
}
