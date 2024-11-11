#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const int INF = 1e9;
const long long LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
long long N;
long long ans = 0LL;
template <size_t sz>
struct bitset_comparer {
  bool operator()(const bitset<sz> &b1, const bitset<sz> &b2) const {
    return b1.to_ulong() < b2.to_ulong();
  }
};
map<int, bitset<35>> ma;
map<bitset<35>, int, bitset_comparer<35>> memo;
int game(bitset<35> b) {
  if (memo[b]) return memo[b];
  if (b.count() == 0) return 0;
  int m = 0;
  for (long long(i) = (0); (i) < (35); (i)++) {
    if (b[i]) m = i;
  }
  set<int> se;
  for (long long(i) = (1); (i) < (m + 1); (i)++) {
    bitset<35> c(b);
    c[i] = 0;
    for (long long(j) = (i + 1); (j) < (35); (j)++) {
      if (c[j]) {
        c[j] = 0;
        c[j - i] = 1;
      }
    }
    se.insert(game(c));
  }
  int subg = 0;
  while (se.count(subg)) subg++;
  return memo[b] = subg;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N;
  for (long long(i) = (0); (i) < (N); (i)++) {
    int a;
    cin >> a;
    for (int p = 2; p * p <= a; p++) {
      int cnt = 0;
      while (a % p == 0) {
        cnt++;
        a /= p;
      }
      ma[p][cnt] = 1;
    }
    if (a > 1) ma[a][1] = 1;
  }
  int grundy = 0;
  for (auto itr : ma) {
    grundy ^= game(itr.second);
  }
  cout << ((grundy != 0) ? "Mojtaba" : "Arpa") << endl;
  return 0;
}
