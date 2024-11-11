#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
const int oo = 1e9 + 5;
int du[] = {-1, 0, 0, 1};
int dv[] = {0, -1, 1, 0};
const long long mod = 1e9 + 7;
long long sqr(long long x) { return x * x; }
int n, x, a[N + 5], ans;
bool vis[N + 5];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> x;
  vis[x] = true;
  for (int i = 1; i < (1 << n); i++) {
    if (!vis[i]) a[ans++] = i;
    vis[i ^ x] = vis[i] = true;
  }
  cout << ans << endl;
  for (int i = 1; i <= ans; i++) cout << (a[i] ^ a[i - 1]) << " ";
  return 0;
}
