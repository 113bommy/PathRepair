#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353, MAX = 2e5 + 5;
long long pot10[MAX];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pot10[0] = 1;
  for (int i = 1; i <= 2e5; ++i) pot10[i] = (pot10[i - 1] * 10) % MOD;
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i)
    cout << (1LL * 180 * pot10[n - i - 1] +
             1LL * (n - i - 1) * 810 * pot10[n - i - 2]) %
                MOD
         << " ";
  cout << "10\n";
}
