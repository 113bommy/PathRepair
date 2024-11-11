#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vc = vector<T>;
using pii = pair<long long, long long>;
void xmax(long long& a, long long b) { a = max(a, b); }
void xmin(long long& a, long long b) { a = min(a, b); }
void print(vc<long long>& a, string second) {
  cerr << "prinitng " << second << "\n";
  for (long long i = 0; i < a.size(); i++) {
    cerr << a[i] << " ";
  }
  cerr << endl;
}
long long mod;
vc<long long> mal(vc<long long> a, vc<long long> b) {
  vc<long long> res = {a[0] * b[0] + a[1] * b[2], a[0] * b[1] + a[1] * b[3],
                       a[2] * b[0] + a[3] * b[2], a[2] * b[1] + a[3] * b[3]};
  for (long long i = 0; i < 4; i++) {
    res[i] = res[i] % mod;
  }
  return res;
}
vc<long long> pow(vc<long long> mat, long long exp) {
  if (exp == 0) return {1, 0, 0, 1};
  if (exp == 1) return mat;
  if (exp % 2 == 0) {
    return pow(mal(mat, mat), exp / 2);
  }
  return mal(mat, pow(mat, exp - 1));
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long max_val = 1e6 + 5;
  long long l, r, k;
  cin >> mod >> l >> r >> k;
  long long a = (r - l + 1) / k;
  long long maxi = a;
  long long b = (r - l + 1) / (k - 1);
  for (long long i = a + 1; i < min(a + max_val, b); i++) {
    long long second = l / i;
    long long start = l;
    if (l % i == 0) {
      start = l;
    } else {
      start = i * (second + 1);
    }
    if (start + (k - 1) * i <= r) xmax(maxi, i);
  }
  for (long long i = 1; i <= max_val; i++) {
    long long cand = r / i;
    if (i > r) break;
    long long anz;
    if (l % cand == 0)
      anz = l / cand;
    else
      anz = l / cand + 1;
    if (i - anz >= k - 1) xmax(maxi, cand);
  }
  vc<long long> mat{0, 1, 1, 1};
  vc<long long> res = pow(mat, maxi - 1);
  cout << res[0] + res[1] << "\n";
}
