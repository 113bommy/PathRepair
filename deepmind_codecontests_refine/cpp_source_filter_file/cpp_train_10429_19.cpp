#include <bits/stdc++.h>
using namespace std;
const int maxn = 1E6 + 5;
int n, k, size, prime[maxn], phi[maxn];
bool vis[maxn];
void init() {
  phi[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!vis[i]) prime[++size] = i, phi[i] = i - 1;
    for (int j = 1; j <= size && prime[j] * i <= n; ++j) {
      phi[prime[j] * i] = phi[i] * (prime[j] - 1);
      vis[prime[j] * i] = 1;
      if (i % prime[j] == 0) {
        phi[prime[j] * i] = phi[i] * prime[j];
        break;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  if (k == 1) {
    cout << 3 << endl;
    return 0;
  }
  init();
  sort(phi + 1, phi + n + 1);
  int sum = 0;
  for (int i = 1; i <= k + 2; ++i) sum += phi[i];
  cout << sum << endl;
  return 0;
}
