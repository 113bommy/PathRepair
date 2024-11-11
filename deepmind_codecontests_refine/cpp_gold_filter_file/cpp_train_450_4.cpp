#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
vector<long long> id;
vector<long long> Mnoz(vector<long long> a, vector<long long> b) {
  int n = a.size();
  vector<long long> c(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      c[i] += b[j] * ((j > i) ? 0 : a[i - j]);
      if (c[i] > MOD) c[i] %= MOD;
    }
  }
  return c;
}
vector<long long> Pot(vector<long long> mat, int w) {
  if (w == 0) return id;
  if (w % 2 == 0) {
    vector<long long> pol = Pot(mat, w / 2);
    return Mnoz(pol, pol);
  }
  return Mnoz(Pot(mat, w - 1), mat);
}
int main() {
  ios_base::sync_with_stdio(0);
  long long n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) id.push_back(0);
  id[0] = 1;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<long long> mat(n, 1);
  mat = Pot(mat, k);
  for (int i = 0; i < n; ++i) {
    long long x = 0;
    for (int j = 0; j < n; ++j) {
      x += a[j] * ((j > i) ? 0 : mat[i - j]);
      if (x > MOD) x %= MOD;
    }
    cout << x << " ";
  }
  return 0;
}
