#include <bits/stdc++.h>
using namespace std;
priority_queue<long long int, vector<long long int>, greater<long long int> >
    ti;
vector<long long int> p[200005], y[300005], f(2000005, 0), b(100005, 0);
long long int vis[100005];
map<pair<long long int, long long int>, long long int> mp;
set<pair<long long int, long long int> > s;
set<long long int> st;
map<long long int, long long int> np, v;
queue<long long int> qy;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int bpow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res % 1000000007;
}
void fact(long long int i) {
  f[0] = 1;
  for (long long int k = 1; k <= i; k++) {
    (f[k] = f[k - 1] * k) %= 1000000007;
  }
}
long long int isprime(long long int n) {
  if (n == 1) return 0;
  for (long long int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  long long int c1 = 0, c2 = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    if (!a[i])
      c2++;
    else
      c1++;
  }
  long long int c3 = 0, c4 = 0, f = n;
  for (long long int i = 0; i < n; i++) {
    if (c1 == c3 or c2 == c4) {
      f = i + 1;
      break;
    }
    if (!a[i])
      c4++;
    else
      c3++;
  }
  cout << f << "\n";
}
