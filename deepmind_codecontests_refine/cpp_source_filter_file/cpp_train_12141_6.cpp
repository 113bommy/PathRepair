#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const int N = 101000;
int n, m;
double dig[N];
char s[N];
vector<int> pr;
int main() {
  scanf("%d", &n);
  m = n;
  scanf("%s", s);
  double ss = 0;
  for (int i = 0; i < m; i++) dig[i] = s[i] - '0', ss += dig[i];
  for (int i = 2; i < m; i++)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      pr.push_back(i);
    }
  pr.push_back(m);
  for (auto p : pr) {
    for (int i = 0; i < m / p; i++) {
      double s = 0;
      for (int j = i; j < m; j += m / p) s += dig[j];
      if (1 || s * ss >= 0) {
        ss -= s;
        s /= m;
        for (int j = i; j < m; j += m / p) dig[j] -= s;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (fabs(dig[i]) >= 1e-9) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
}
