#include <bits/stdc++.h>
using namespace std;
void debug() { cerr << "\n"; }
template <typename H, typename... T>
void debug(H h, T... t) {
  cerr << h;
  if (sizeof...(t)) cerr << ", ";
  debug(t...);
}
const int N = 2e5 + 5, INF = 1e9 + 5, mod = 1e6 + 3;
long long pot(long long a, long long b) {
  if (b == 0) return 1ll;
  if (b == 1) return a;
  long long c = pot(a, b / 2);
  c = (c * c) % mod;
  return (c * pot(a, b & 1)) % mod;
}
int odw(int a) { return pot(a, mod - 2); }
int main() {
  int k = 11;
  vector<vector<int> > V(k + 1);
  for (int i = 1; i <= k; i++) {
    cout << "? " << i << endl;
    V[i].resize(k + 1);
    cin >> V[i][k];
    V[i][0] = 1;
    for (int j = 1; j < k; j++) {
      V[i][j] = (V[i][j - 1] * i) % mod;
    }
  }
  vector<int> V2(k), V3(k);
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      if (j == i) continue;
      int c = (V[j][i - 1] * 1ll * odw(V[i][i - 1])) % mod;
      for (int l = i - 1; l <= k; l++) {
        V[j][l] -= (c * 1ll * V[i][l]) % mod;
        V[j][l] += mod;
        V[j][l] %= mod;
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    V2[i - 1] = (V[i][k] * 1ll * odw(V[i][i - 1])) % mod;
  }
  for (int i = 0; i < mod; i++) {
    int t = 1;
    long long ans = 0;
    for (int j = 0; j < k; j++) {
      ans += (V2[j] * 1ll * t) % mod;
      t = (t * i) % mod;
    }
    ans = ans % mod;
    if (!ans) {
      cout << "! " << i << endl;
      return 0;
    }
  }
  cout << "! " << -1 << endl;
}
