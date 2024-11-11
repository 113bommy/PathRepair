#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int n, best[MAXN];
int go(int m) {
  int ans = 100;
  for (int tm = m; tm; tm /= 10) {
    int aux = tm % 10;
    if (aux > 0) ans = min(ans, 1 + best[m - aux]);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    best[i] = go(i);
  }
  cout << best[n] << endl;
  return 0;
}
