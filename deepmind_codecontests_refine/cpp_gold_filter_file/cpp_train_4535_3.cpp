#include <bits/stdc++.h>
using namespace std;
const int inf_int = 2e9;
const long long inf_ll = 2e18;
int Gcd(int p, int q) { return q == 0 ? p : Gcd(q, p % q); }
int Pow(int p, int q) {
  int ans = 1;
  while (q) {
    if (q & 1) ans = ans * p;
    p = p * p;
    q >>= 1;
  }
  return ans;
}
inline int read() {
  int ra, fh;
  char rx;
  rx = getchar(), ra = 0, fh = 1;
  while ((rx < '0' || rx > '9') && rx != '-') rx = getchar();
  if (rx == '-') fh = -1, rx = getchar();
  while (rx >= '0' && rx <= '9') ra *= 10, ra += rx - 48, rx = getchar();
  return ra * fh;
}
int a[300005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  n = read();
  for (int i = (1), _ed = (n); i <= _ed; i++) {
    a[i] = read();
  }
  sort(a + 1, a + 1 + n);
  printf("%d\n", a[(n + 1) / 2]);
  return 0;
}
