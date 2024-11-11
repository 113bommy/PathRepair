#include <bits/stdc++.h>
using namespace std;
int _I() {
  int x;
  scanf("%d", &x);
  return x;
}
const int lmt = 10000000;
bool prime[lmt + 5];
int rng = 1, v[lmt + 5];
void sv() {
  v[0] = 2;
  for (int i = 4; i <= lmt; i += 2) prime[i] = 1;
  for (int i = 3; i <= lmt; i += 2) {
    if (!prime[i]) {
      v[rng++] = i;
      for (int j = i * 3; j <= lmt; j += i << 1) prime[j] = 1;
    }
  }
  prime[1] = 1;
}
int rev(int n) {
  int num = 0;
  while (n) {
    num *= 10;
    num += (n % 10);
    n /= 10;
  }
  return num;
}
void solve() {
  int n = _I();
  int ans[100001];
  for (int i = 13, j = 1; j <= 11184; i++) {
    if (i != rev(i) && !prime[i] && !prime[rev(i)]) ans[j++] = i;
  }
  cout << ans[n] << "\n";
}
int main() {
  sv();
  solve();
  return 0;
}
