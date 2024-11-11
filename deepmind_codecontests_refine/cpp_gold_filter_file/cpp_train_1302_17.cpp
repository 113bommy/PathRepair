#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7;
int vis[1000000 + 20];
int main() {
  long long p, k;
  cin >> p >> k;
  long long ans = 1;
  memset(vis, 0, sizeof(vis));
  if (k == 0) {
    for (int i = 1; i < p; i++) {
      ans = (ans * p) % Mod;
    }
    cout << ans << endl;
  } else {
    ans = 1;
    long long kw = 1000000;
    for (long long e = 0; e < p; e++) {
      kw = 1000000;
      long long i = e;
      int z = 0;
      if (!vis[i]) {
        while (!vis[i]) {
          kw = min(kw, i);
          vis[i] = 1;
          i = (i * k) % p;
          z++;
        }
        if (kw || k == 1) ans = (ans * (p)) % Mod;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
