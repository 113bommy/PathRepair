#include <bits/stdc++.h>
using namespace std;
const long long int N = 21;
bool is_ind[1 << N];
long long int mx_ind[1 << N];
long long int adj1[N], adj2[N], m[1 << N], adjm[N];
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cout << setprecision(12) << fixed;
  ;
  long long int n, k;
  cin >> n >> k;
  long long int x = n / 2, y = n - x;
  for (long long int i = 0; i < n; i++) {
    long long int z = 1, r = 1;
    for (long long int j = 0; j < n; j++) {
      long long int w;
      cin >> w;
      w ^= (i != j);
      if (i < x && j < x) {
        adj1[i] += (w * z);
        z *= 2;
      }
      if (i < x && j >= x) {
        adjm[i] += (w * r);
        r *= 2;
      }
      if (i >= x && j >= x) {
        adj2[i - x] += (w * z);
        z *= 2;
      }
    }
  }
  is_ind[0] = true;
  for (long long int i = 1; i < (1 << x); i++) {
    if (is_ind[(i ^ (1 << (__builtin_ctz(i))))] &&
        !((i ^ (1 << (__builtin_ctz(i)))) & adj1[__builtin_ctz(i)]))
      is_ind[i] = true;
    m[i] = (m[(i ^ (1 << (__builtin_ctz(i))))] | adjm[__builtin_ctz(i)]);
  }
  for (long long int i = 1; i < (1 << y); i++) {
    long long int t = i, mx = 0;
    for (; t > 0; t -= (t & -t)) {
      long long int f = mx_ind[(i ^ (1 << (__builtin_ctz(t))))];
      if (!((i ^ (1 << (__builtin_ctz(t)))) & adj2[__builtin_ctz(t)])) f++;
      mx = max(mx, f);
    }
    mx_ind[i] = mx;
  }
  long long int fin = 0;
  for (long long int i = 0; i < (1 << x); i++) {
    if (is_ind[i]) {
      fin = max(fin, __builtin_popcount(i) + mx_ind[m[i] ^ ((1 << (y)) - 1)]);
    }
  }
  if (!fin) return cout << 0, 0;
  long double cnt = (long double)k / (long double)fin;
  cnt *= cnt;
  fin = fin * (fin - 1) / 2;
  return cout << cnt * fin, 0;
}
