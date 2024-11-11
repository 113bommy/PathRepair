#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
const ll MOD = 1000000007;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  char c;
  ll f[5] = {1, 1, 0, 0, 0};
  ll t[5];
  while ((c = getchar()) != '\n') {
    for (int i = (0); i < (5); ++i) t[i] = 0;
    if (c == '0' || c == '?') t[0] += f[0] + f[4];
    if (c == '1' || c == '?') {
      t[1] += f[0] + f[4];
      t[4] += f[3];
    }
    if (c == '2' || c == '?') t[2] += f[3];
    if (c == '*' || c == '?') t[3] += f[1] + f[2] + f[3];
    for (int i = (0); i < (5); ++i) {
      f[i] = (t[i] % MOD);
    }
  }
  cout << f[0] + f[3] + f[4] << "\n";
}
