#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n, p, k;
int a[maxn];
map<int, int> m;
long long pw(int w) { return 1ll * w * w % p; }
int cal(int w) { return ((pw(w) * pw(w) % p - 1ll * k * w % p) % p + p) % p; }
int main() {
  cin >> n >> p >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    m[cal(a[i])]++;
  }
  long long ans = 0;
  for (auto i : m) {
    ans = ans + 1ll * i.second * (i.second - 1) / 2;
  }
  cout << ans;
}
