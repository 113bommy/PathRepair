#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int N = 7000;
int mu[N + 1], n, q, t, x, y, z;
bitset<N + 5> f[N + 1], a[N + 1], b[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = (1); i < (N + 1); i++) mu[i] = 1;
  for (int i = (2); i < (N + 1); i++)
    for (int j = i * i; j <= N; j += i * i) mu[j] = 0;
  for (int i = (1); i < (N + 1); i++)
    for (int j = i; j <= N; j += i) a[j][i] = 1, f[i][j] = mu[j / i];
  while (q--) {
    cin >> t >> x >> y;
    if (t == 1)
      b[x] = a[y];
    else {
      if (t != 4) cin >> z;
      if (t == 2)
        b[x] = b[y] ^ b[z];
      else if (t == 3)
        b[x] = b[y] & b[z];
      else
        cout << ((b[x] & f[y]).count() & 1);
    }
  }
  return 0;
}
