#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const long long INF = 1e18;
int n, k;
vector<int> v;
int main() {
  scanf("%d%d", &n, &k);
  k = n - k + 1;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (x >= k) v.push_back(i);
  }
  long long ans = 1;
  for (int i = 1; i < v.size(); i++) ans = ans * (v[i] - v[i - 1]) % mod;
  printf("%lld %lld", 1ll * n * (n + 1) / 2 - 1ll * k * (k - 1) / 2, ans);
}
