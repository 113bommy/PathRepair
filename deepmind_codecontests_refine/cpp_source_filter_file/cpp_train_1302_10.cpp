#include <bits/stdc++.h>
using namespace std;
const int MOD = 1E9 + 7;
int parent[1111111];
int nc;
int find(int x) {
  if (x == parent[x]) return x;
  return parent[x] = find(parent[x]);
}
void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  nc--;
  parent[b] = a;
}
long long fmp(long long x, int e) {
  if (e == 0) return 1;
  long long w = fmp(x, e / 2);
  w = (w * w) % MOD;
  if (e & 1) w = (w * x) % MOD;
  return w;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  long long p, k;
  cin >> p >> k;
  if (k == 0) {
    cout << fmp(p, p - 1) << '\n';
    return 0;
  }
  nc = p - 1;
  for (long long i = 1; i < p; i++) parent[i] = i;
  for (long long i = 1; i < p; i++) merge(i, (i * k) % p);
  cout << fmp(p, nc) << '\n';
  return 0;
}
