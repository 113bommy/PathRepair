#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5;
int mod, n;
int fact[maxn];
inline int sum(int a, int b) {
  if (a + b >= mod) {
    return a + b - mod;
  } else if (a + b < 0) {
    return a + b + mod;
  }
  return a + b;
}
inline int mul(int a, int b) { return (long long)a * b % mod; }
void precompute() {
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> mod;
  precompute();
  int sol = 0;
  for (int i = 0; i < n; i++) {
    if (!i) {
      sol = sum(sol, mul(n, mul(n - i, fact[n - 1])));
    } else {
      sol = sum(sol,
                mul(n - i, mul((i + 1) * i,
                               mul(fact[i - 1], mul(n - i, fact[n - i - 1])))));
    }
  }
  cout << sol << '\n';
  return 0;
}
