#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
const int mod = 1000 * 1000 * 1000 + 7;
int n;
int a[maxn];
int last[maxn];
int fen[maxn * 4];
void add(int x, int val) {
  for (int k = x; k < maxn; k += k & -k) fen[k] = (fen[k] + val) % mod;
}
int get(int x) {
  int ans = 0;
  for (int k = x; k; k -= k & -k) ans = (ans + fen[k]) % mod;
  return ans;
}
int main() {
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int ted = (get(x) + 1) % mod;
    int pp = 1LL * (ted - last[x] + mod) % mod * x % mod;
    add(x, pp);
    ans += pp;
    ans %= mod;
    last[x] = ted;
  }
  cout << ans << endl;
}
