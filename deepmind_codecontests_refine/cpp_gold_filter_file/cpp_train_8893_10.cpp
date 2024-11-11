#include <bits/stdc++.h>
using namespace std;
int n, k, d, f[101][2];
const int MOD = 1e9 + 7;
void input() { cin >> n >> k >> d; }
void process() {
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= min(i, k); ++j)
      if (j < d) {
        f[i][0] = (f[i][0] + f[i - j][0]) % MOD;
        f[i][1] = (f[i][1] + f[i - j][1]) % MOD;
      } else
        f[i][1] = ((f[i][1] + f[i - j][0]) % MOD + f[i - j][1]) % MOD;
}
void output() { cout << f[n][1] << '\n'; }
int main() {
  input();
  process();
  output();
}
