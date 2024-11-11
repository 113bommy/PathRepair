#include <bits/stdc++.h>
using namespace std;
long long a, b, z, k, i, j, n;
int main() {
  cin >> n >> a >> b;
  for (i = 1; i < n + 1; i++) {
    cin >> z;
    cout << ((z * a - (z * a / b) * b) / a) << endl;
  }
}
