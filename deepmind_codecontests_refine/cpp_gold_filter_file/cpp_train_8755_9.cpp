#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long fpow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
void setmin(T& a, T val) {
  if (a > val) a = val;
}
template <class T>
void setmax(T& a, T val) {
  if (a < val) a = val;
}
void addmod(long long& a, long long val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
void submod(long long& a, long long val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }
const int N = 100005;
vector<pair<int, int> > a;
multiset<int> q;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, x, y;
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    a.push_back(make_pair(l, r));
  }
  sort(a.begin(), a.end());
  long long ans = 0;
  for (int i = 0; i < a.size(); i++) {
    long long l = a[i].first, r = a[i].second;
    if (q.size() == 0) {
      ans += x + (r - l) * y;
      ans = ans % MOD;
      q.insert(r);
    } else {
      set<int>::iterator it = q.lower_bound(l);
      long long k = *it;
      if (it != q.begin()) {
        it--;
        k = *it;
      }
      if (k < l) {
        q.erase(it);
        if ((l - k) * y <= x) {
          ans = ans + (r - k) * y;
          ans = ans % MOD;
          q.insert(r);
        } else {
          ans = ans + x + (r - l) * y;
          ans = ans % MOD;
          q.insert(r);
        }
      } else {
        ans = ans + x + (r - l) * y;
        ans = ans % MOD;
        q.insert(r);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
