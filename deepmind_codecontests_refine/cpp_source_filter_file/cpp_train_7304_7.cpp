#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18 + 1;
long long int md(long long int a, long long int p) { return (a % p + p) % p; }
int main() {
  int n;
  long long int p, k;
  scanf("%d%d%d", &n, &p, &k);
  vector<long long int> a(n);
  map<int, long long int> am;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
    long long int f = md(
        ((((a[i] * a[i]) % p) * ((a[i] * a[i]) % p)) % p - (k * a[i]) % p) % p,
        p);
    am[f]++;
  }
  long long int ans = 0;
  for (auto i : am) {
    ans = ans + i.second * (i.second - 1) / 2;
  }
  printf("%lld", ans);
  return 0;
}
