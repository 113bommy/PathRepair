#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int f[N];
int main() {
  long long n, m;
  cin >> n >> m;
  f[1] = 1;
  long long sum = 1;
  for (int i = 2; i <= n; i++) {
    f[i] += sum;
    for (int l = 2, r = 0; l <= i; l = r + 1) {
      r = min(i, i / (i / l));
      f[i] += 1ll * f[i / l] * (r - l + 1);
      f[i] %= m;
    }
    sum += f[i];
    sum %= m;
  }
  cout << f[n] << endl;
}
