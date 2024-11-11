#include <bits/stdc++.h>
using namespace std;
vector<int> valid;
int a, b, n, maxi;
long long modInverse(long long a, long long p) {
  long long ne = 1, old = 0, q = p, r, h;
  int pos = 0;
  while (a > 0) {
    r = q % a;
    q = q / a;
    h = q * ne + old;
    old = ne;
    ne = h;
    q = a;
    a = r;
    pos = !pos;
  }
  return pos ? old : (p - old);
}
void rec(int val) {
  if (val > maxi) return;
  if (val * 10 + a < maxi) {
    valid.push_back(val * 10 + a);
    rec(val * 10 + a);
  }
  if (val * 10 + b < maxi) {
    valid.push_back(val * 10 + b);
    rec(val * 10 + b);
  }
  return;
}
long long fact[1000010];
int main() {
  fact[0] = 1;
  for (long long i = 1; i < 1000001; i++)
    fact[i] = (i * fact[i - 1]) % 1000000007;
  cin >> a >> b >> n;
  if (a > b) swap(a, b);
  maxi = b * n;
  rec(0);
  long long ans = 0;
  for (int i = 0; i < valid.size(); i++) {
    int marker = valid[i] / a;
    for (int j = 0; j <= min(n, marker); j++) {
      int temp = j * a;
      if ((valid[i] - temp) % b == 0 and (valid[i] - temp) / b == (n - j)) {
        long long temp1 = fact[n];
        temp1 = (temp1 * modInverse(fact[j], 1000000007)) % 1000000007;
        temp1 = (temp1 * modInverse(fact[n - j], 1000000007)) % 1000000007;
        ans = (ans + temp1) % 1000000007;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
