#include <bits/stdc++.h>
using namespace std;
int f[4000001];
int n, m;
int main() {
  cin >> n >> m;
  f[1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = (i == 2) ? 2 : (f[i] + f[i - 1] * 2 + 1) % m;
    for (int j = 2; j * i <= n; j++) {
      int dif = f[i] - f[i - 1];
      if (dif < 0) dif = m + dif;
      f[i * j] = (f[i * j] + dif) % m;
    }
  }
  cout << f[n];
}
