#include <bits/stdc++.h>
using namespace std;
const int BASE = 1000000007;
const int MAXN = 100000;
long long f[MAXN + 10];
int n, m;
int main() {
  cin >> n >> m;
  f[0] = 2;
  f[1] = 2;
  for (int i = 2; i <= max(n, m); i++) {
    f[i] = (f[i - 1] + f[i - 2]) % BASE;
  }
  cout << (f[n] + f[m] - 2) % BASE << endl;
  return 0;
}
