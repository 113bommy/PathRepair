#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  if (b == (long long int)0) return (long long int)1;
  long long int c = power(a, b >> 1);
  c %= ((long long int)1000000009);
  c *= c;
  c %= ((long long int)1000000009);
  if (b & 1) {
    c *= a;
    c %= ((long long int)1000000009);
  }
  return c;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  long long int a, b, A = (long long int)1, B = (long long int)1, C;
  cin >> n >> a >> b >> k;
  long long int s[k], ans = (long long int)0, D;
  string s1;
  cin >> s1;
  for (int i = 0; i < s1.size(); i++) {
    s[i] = (long long int)1;
    if (s1[i] == '-') {
      s[i] *= ((long long int)(-1));
    }
  }
  for (int i = 0; i < k; i++) {
    C = power(A, ((long long int)1000000007));
    D = B * C;
    D %= ((long long int)1000000009);
    ans += s[i] * D;
    ans %= ((long long int)1000000009);
    A *= a;
    A %= ((long long int)1000000009);
    B *= b;
    B %= ((long long int)1000000009);
  }
  C = power(A, ((long long int)1000000007));
  long long int r = B * C;
  r %= ((long long int)1000000009);
  n++;
  long long int r1 = power(r, (long long int)(n / k));
  r1--;
  r--;
  r %= ((long long int)1000000009);
  if (b != a) {
    C = power(r, ((long long int)1000000007));
    r1 *= C;
  } else
    r1 = n / k;
  r1 %= ((long long int)1000000009);
  ans *= r1;
  ans %= ((long long int)1000000009);
  A = power(a, (long long int)(n - 1));
  ans *= A;
  ans %= ((long long int)1000000009);
  while (ans < 0) ans += ((long long int)1000000009);
  cout << ans << " ";
}
