#include <bits/stdc++.h>
using namespace std;
inline int add(int a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
  return a;
}
inline int mul(int a, int b) { return (a * 1ll * b) % 1000000007; }
inline int pow(int a, int b) {
  int rt = 1;
  while (b > 0) {
    if (b & 1) rt = mul(rt, a);
    a = mul(a, a);
    b >>= 1;
  }
  return rt;
}
inline bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
inline long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
inline long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    long long int n, a, b;
    cin >> n >> a >> b;
    if (2 * a <= b)
      cout << n * a << "\n";
    else {
      long long int k = n / b;
      n -= k * 2;
      if (n > 0)
        cout << k * b + n * a << "\n";
      else
        cout << k * b << "\n";
    }
  }
}
