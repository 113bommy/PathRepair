#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int nag = 2e5 + 5;
template <typename T>
void add(T& a, T b) {
  a += b;
  while (a >= mod) a -= mod;
  while (a < 0) a += mod;
}
template <typename T>
void mul(T& a, T b) {
  a = a * b % mod;
}
template <typename T>
void up_self(T& a, T b) {
  a = max(a, b);
}
template <typename T>
void min_self(T& a, T b) {
  a = min(a, b);
}
string find_largest_pref_palindrome(const string& a) {
  string second = a;
  reverse(second.begin(), second.end());
  second = a + "%" + second;
  int c = 0;
  vector<int> pref(2 * ((int)a.size()) + 2);
  for (int i = 1; i < second.size(); i++) {
    while (c != 0 && second[i] != second[c]) c = pref[c - 1];
    if (second[i] == second[c]) c++;
    pref[i] = c;
  }
  return second.substr(0, c);
}
long long int binexpomodulo(long long int x, long long int y) {
  long long int res = 1;
  x %= mod;
  if (!x) return 0;
  while (y) {
    if (y & 1) {
      mul(res, x);
    }
    mul(x, x);
    y >>= 1;
  }
  return res;
}
long long int nCrInOr(long long int n, long long int r) {
  long long int res = 1;
  if (r > n - r) r = n - r;
  long long int rin = 1;
  for (long long int i = 1; i <= r; i++) rin = (rin * i) % mod;
  rin = binexpomodulo(rin, mod - 2);
  for (long long int i = 1; i <= r; i++) res = (res * (n - i + 1)) % mod;
  res = (res * rin) % mod;
  return res;
}
int msb(long long int n) {
  int ans;
  for (int i = 0; i < 64; i++)
    if (n & (1LL << i)) ans = i + 1;
  return ans;
}
long long int get_(vector<long long int>& a, int pos) {
  long long int res = 0;
  for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
    res += a[pos];
  }
  return res;
}
void upd(vector<long long int>& a, int pos, int val) {
  for (; pos < a.size(); pos = (pos | (pos + 1))) a[pos] += val;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<long long int> pref(n), suff(n);
  vector<long long int> ar(n);
  for (int i = 0; i < n; i++) cin >> ar[i];
  ;
  pref[0] = ar[0] * a;
  suff[n - 1] = ar[n - 1] * c;
  for (int i = 1; i < n; i++) {
    pref[i] = max(pref[i - 1], ar[i] * a);
  }
  for (int i = n - 2; i >= 0; i--) {
    suff[i] = max(suff[i + 1], ar[i] * c);
  }
  long long int ans = -(long long int)1e18;
  for (int i = 0; i < n; i++) {
    up_self(ans, pref[i] + b * ar[i] + suff[i]);
  }
  cout << ans << "\n";
  return 0;
}
