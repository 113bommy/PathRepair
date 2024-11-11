#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long ans;
int n;
char x[101];
int main() {
  gets(x);
  n = strlen(x);
  int p = 1;
  for (int i = n - 1; i >= 0; --i) {
    if (x[i] == '1') ans = (ans + p) % mod;
    if (!i) ans = ans * p % mod;
    p = 2 * p % mod;
  }
  cout << ans << endl;
  return 0;
}
