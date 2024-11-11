#include <bits/stdc++.h>
#pragma GCC Optimize("Ofast")
using namespace std;
long long mpow(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  while (b) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
    b >>= 1;
  }
  return res % 1000000007;
}
bool primechk(long long x) {
  if (x == 1) return false;
  if (x == 2) return true;
  for (long long i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
bool powerof2(long long x) { return (x && !(x & (x - 1))); }
template <typename T>
vector<T> read(T n) {
  vector<T> v(n);
  for (auto &x : v) cin >> x;
  return v;
}
template <typename T>
void print(T arr) {
  for (auto x : arr) cout << x << " ";
}
const int Mxn = 1e3 + 7;
vector<int> g[Mxn];
map<string, int> mp;
bool ispal(string x) {
  string a = x;
  reverse(a.begin(), a.end());
  return x == a;
}
void solve() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = s.size();
  if (n % k != 0) {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i + k < n; i += 1ll * n / k) {
    string a(s.begin() + i, s.begin() + (i + 1ll * n / k));
    if (!ispal(a)) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  solve();
  return 0;
}
