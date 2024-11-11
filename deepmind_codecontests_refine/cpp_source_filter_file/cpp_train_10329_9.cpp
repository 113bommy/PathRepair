#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const int mod = (int)1e9 + 7;
const int N = 1e5 + 10;
const long long inf = 1e11;
long long nxt[N][26];
const long long maxm = 250005;
long long fact[maxm];
void solve() {
  long long n, m;
  cin >> n >> m;
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = i * fact[i - 1], fact[i] = fact[i] % m;
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long curr = (fact[i] * fact[n - i + 1]) * 1LL * (n - i + 1LL);
    ans += curr;
    ans = ans % m;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
