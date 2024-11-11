#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long n_ = 1e5 + 1000;
const long double PI = acos(-1.0);
long long gcd(long long a, long long b) { return (a ? gcd(b % a, a) : b); }
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
long long power(long long a, long long n, long long mod) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
      p %= mod;
    }
    n >>= 1;
    a *= a;
    a %= mod;
  }
  return p % mod;
}
bool vowel(char ch) {
  if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    return true;
  else
    return false;
}
string f0 =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
string f =
    "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
string ff[3] = {"What are you doing while sending \"",
                "\"? Are you busy? Will you send \"", "\"?"};
long long sz[100005];
char solve(long long n, long long k) {
  if (k > sz[n]) return '.';
  if (n == 0) return f0[k];
  if (ff[0].size() > k) return ff[0][k];
  k -= ff[0].size();
  if (sz[n - 1] > k) return solve(n - 1, k);
  k -= sz[n - 1];
  if (ff[1].size() > k) return ff[1][k];
  k -= ff[1].size();
  if (sz[n - 1] > k) return solve(n - 1, k);
  k -= sz[n - 1];
  return ff[2][k];
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sz[0] = f0.size();
  for (long long i = 1; i < 55; i++) {
    sz[i] = f.size() + 2 * sz[i - 1];
  }
  for (long long i = 55; i < 100005; i++) sz[i] = sz[i - 1];
  long long q, n, k;
  cin >> q;
  while (q--) {
    cin >> n >> k;
    k--;
    cout << solve(n, k);
  }
  return 0;
}
