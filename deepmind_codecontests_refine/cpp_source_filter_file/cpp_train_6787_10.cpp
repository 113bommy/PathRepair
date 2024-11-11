#include <bits/stdc++.h>
using namespace std;
int n, m;
long long f[100012];
const int mod = 1e9 + 7;
void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i <= 100012 - 2; i++) {
    f[i] = (f[i - 1] + f[i - 2]) % mod;
  }
  cout << 2ll * (f[n] + f[m] - 1);
}
int main() {
  input();
  return 0;
}
