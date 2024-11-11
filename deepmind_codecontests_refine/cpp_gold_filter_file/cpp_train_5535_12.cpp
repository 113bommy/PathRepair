#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T bpow(T p, T e) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p);
    p = (p * p);
  }
  return (T)ret;
}
int toInt(string s) {
  int sm;
  stringstream ss(s);
  ss >> sm;
  return sm;
}
int toLlint(string s) {
  long long int sm;
  stringstream ss(s);
  ss >> sm;
  return sm;
}
const double eps = 1e-9;
int ts, kk = 1;
long long int n, m, rs;
int main() {
  int t, i, j, k;
  cin >> n >> m;
  while (n--) {
    scanf("%d%d%d", &j, &k, &t);
    j--;
    k--;
    if (j == k) {
      printf("%d\n", t);
      continue;
    }
    long long int q = t % (m + m - 2);
    rs = t;
    if (q >= m) {
      q = m + m - 2 - q;
      if (j <= q) {
        rs += q - j;
        q = j;
        if (k <= q)
          rs += q - k;
        else
          rs += q + k;
      } else {
        rs += q + j;
        q = j;
        if (q <= k)
          rs += k - q;
        else
          rs += m - 1 - q + m - 1 - k;
      }
    } else {
      if (j >= q) {
        rs += j - q;
        q = j;
        if (q <= k)
          rs += k - q;
        else
          rs += m - 1 - q + m - 1 - k;
      } else {
        rs += m - 1 - q + m - 1 - j;
        q = j;
        if (k <= q)
          rs += q - k;
        else
          rs += q + k;
      }
    }
    cout << rs << '\n';
  }
  return 0;
}
