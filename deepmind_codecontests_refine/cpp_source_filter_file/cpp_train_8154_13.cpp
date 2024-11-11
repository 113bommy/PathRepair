#include <bits/stdc++.h>
using namespace std;
long long odp = -9000000000000000000;
int n, u, r;
long long maxi(long long a, long long b) {
  if (a > b) return a;
  return b;
}
void Backtrack(vector<long long> a, vector<long long>& b, vector<long long>& k,
               vector<long long>& p, int nr, bool xoruj) {
  long long wyn = 0;
  for (int i = 0; i < n; ++i) wyn += a[i] * k[i];
  if (nr == u + 1) {
    odp = maxi(odp, wyn);
    return;
  }
  if ((u - nr) % 2 == 0) odp = maxi(odp, wyn);
  if (xoruj) {
    vector<long long> t(n);
    for (int i = 0; i < n; ++i) t[i] = a[i] ^ b[i];
    Backtrack(t, b, k, p, nr + 1, false);
  }
  vector<long long> t(n);
  for (int i = 0; i < n; ++i) t[i] = a[p[i] - 1] + r;
  Backtrack(t, b, k, p, nr + 1, true);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> u >> r;
  vector<long long> a(n), b(n), k(n), p(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < n; ++i) cin >> k[i];
  for (int i = 0; i < n; ++i) cin >> p[i];
  Backtrack(a, b, k, p, 1, true);
  cout << odp;
  return 0;
}
