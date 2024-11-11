#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
using unset = unordered_set<T>;
template <class K, class V>
using unmap = unordered_map<K, V>;
const ll llinf = 1LL << 60;
const int MOD = 1e9 + 7;
vector<int> bases;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int randint(int a = 0, int b = INT_MAX) {
  return a + abs(int(rng())) % (b - a);
}
inline ll randll() {
  ll a = randint();
  a *= INT_MAX;
  a += randint();
  return a;
}
inline int pot(int n, int k) {
  ll ret = 1;
  while (k) {
    if (k & 1) {
      ret *= n;
      ret %= MOD;
    }
    n *= n;
    n %= MOD;
    k >>= 1;
  }
  return ret;
}
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int MAXN = 1e5 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 10; ++i)
    bases.push_back(randll() % (MOD - 2 * 13893829) + 13893829);
  int n;
  cin >> n;
  int c[2] = {0, 0};
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    c[0] += a / 2, c[1] += a / 2;
    if (a % 2 == 1) c[i % 2]++;
  }
  cout << min(c[0], c[1]) << '\n';
  return 0;
}
