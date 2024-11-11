#include <bits/stdc++.h>
using namespace std;
int f[250000 + 1];
int main() {
  int n = ({
    int x;
    scanf("%d", &x);
    x;
  }),
      p = ({
        int x;
        scanf("%d", &x);
        x;
      });
  f[0] = 1;
  for (int i = (1); i < (n + 1); i += (1)) f[i] = f[i - 1] * (long long)i % p;
  int ans = 0;
  for (int i = (0); i < (n); i += (1)) {
    ans += (n - i) * (long long)(n - i) % p * (long long)f[i + 1] % p *
           f[n - i - 1] % p;
    ans %= p;
  }
  cout << ans << "\n";
}
