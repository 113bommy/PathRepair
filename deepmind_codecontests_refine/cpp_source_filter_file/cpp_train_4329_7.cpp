#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool updateMin(T& a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool updateMax(T& a, T b) {
  return a < b ? a = b, 1 : 0;
}
inline int nextInt() {
  int x;
  scanf("%d", &x);
  return x;
}
inline long long nextI64() {
  long long d;
  cin >> d;
  return d;
}
inline char nextChr() {
  scanf(" ");
  return getchar();
}
inline string nextStr() {
  string s;
  cin >> s;
  return s;
}
inline double nextDbf() {
  double x;
  scanf("%lf", &x);
  return x;
}
inline long long nextlld() {
  long long d;
  scanf("%lld", &d);
  return d;
}
inline long long next64d() {
  long long d;
  scanf("%I64d", &d);
  return d;
}
const int MAXN = 100005;
const int MAXM = 1000005;
const int MOD = 1000000007;
const long long PRIME_A = 1004535809LL;
const long long PRIME_B = 469762049LL;
const long long hash_ = 10009;
long long _1 = 1, _2 = 1;
long long fac[MAXM];
int hash_a[MAXM], hash_b[MAXM];
void _hash(int _) {
  hash_a[_] = (hash_a[_] + _1) % PRIME_A;
  hash_b[_] = (hash_b[_] + _2) % PRIME_B;
}
void _roll() {
  _1 = (_1 * hash_) % PRIME_A;
  _2 = (_2 * hash_) % PRIME_B;
}
void init() {
  fac[0] = fac[1] = 1;
  for (int i = 2; i < MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
}
int main() {
  init();
  int n = nextInt();
  int m = nextInt();
  for (int i = 0; i < n; i++) {
    int g = nextInt();
    for (int j = 0; j < g; j++) {
      _hash(nextInt());
    }
    _roll();
  }
  map<pair<int, int>, int> cnt;
  for (int i = 1; i <= m; i++) cnt[make_pair(hash_a[i], hash_b[i])]++;
  long long ans = 1;
  for (auto elem : cnt) {
    ans = (ans * fac[elem.second]) % MOD;
  }
  cout << ans << endl;
  return 0;
}
