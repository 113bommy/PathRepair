#include <bits/stdc++.h>
using namespace std;
const long long Inf = 1e10;
const long long MaxN = 5e5 + 5;
const long long md = 998244353;
long long binpow(long long n, long long m, long long mod = md) {
  long long Res = 1;
  while (m) {
    if (m & 1) {
      Res *= n;
      Res %= mod;
    }
    n *= n;
    n %= mod;
    m >>= 1;
  }
  return Res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  long long N;
  cin >> N;
  long long inv = binpow(N, md - 2);
  vector<long long> Mt(N);
  for (int i = 0; i < N; i++) {
    cin >> Mt[i];
  }
  sort((Mt).begin(), (Mt).end(),
       [=](long long a, long long b) { return a > b; });
  vector<long long> Ans;
  Ans.push_back(0);
  for (int i = 0; i < N; i++) {
    long long a = Ans.back() + Mt[i];
    if (a >= md) a -= md;
    Ans.push_back(a);
  }
  for (int k = 1; k <= N; ++k) {
    int ans = 0;
    for (int i = 0, j = 0; i < N; i += k, ++j) {
      ans += (j * (Ans[min(N, 1ll * i + k)] + -Ans[i])) % md;
      if (ans >= md) ans -= md;
    }
    cout << (ans * inv) % md << '\n';
  }
  return 0;
}
