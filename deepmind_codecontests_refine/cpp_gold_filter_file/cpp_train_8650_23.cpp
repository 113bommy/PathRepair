#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class c>
struct rge {
  c h, n;
};
template <class c>
rge<c> range(c h, c n) {
  return rge<c>{h, n};
}
template <class c, class F>
struct rgm {
  c h, n;
  F f;
};
template <class c, class F>
rgm<c, F> map_range(c b, c e, F f) {
  return rgm<c, F>{b, e, f};
}
template <class c, class F>
rgm<typename c::const_iterator, F> map_range(const c &x, F f) {
  return map_range(x.begin(), x.end(), f);
}
template <class c>
auto dud(c *r) -> decltype(cerr << *r);
template <class c>
char dud(...);
struct muu {
  template <class c>
  muu &operator<<(const c &) {
    return *this;
  }
  muu &operator()() { return *this; }
};
const int nax = 101;
using ll = long long;
const ll mod = 97;
ll ways[nax][nax * nax];
int cou[nax];
void add(ll &a, ll b) {
  a += b;
  if (a > mod) a -= mod;
}
ll binom[nax][nax];
int main() {
  int diff = 0;
  for (int i = 0; i < nax; ++i) binom[i][i] = binom[i][0] = 1;
  for (int i = 1; i < nax; ++i)
    for (int j = 1; j < i; ++j)
      binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % mod;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    cou[x]++;
  }
  for (int i = 0; i < nax; ++i)
    if (cou[i]) diff++;
  ways[0][0] = 1;
  int seen_so_far = 0, sum_so_far = 0;
  for (int i = 1; i < nax; ++i) {
    for (int l = 0; l < cou[i]; ++l) {
      for (int c = seen_so_far; c >= 0; --c)
        for (int s = 0; s <= sum_so_far; ++s)
          add(ways[c + 1][s + i], ways[c][s]);
      seen_so_far++;
      sum_so_far += i;
    }
  }
  int ans = 1;
  bool whole = false;
  for (int i = 1; i < nax; ++i) {
    for (int l = ans + 1; l <= cou[i]; ++l) {
      (muu() << __FUNCTION__ << "#" << 103 << ": ")
          << "["
             "i"
             ": "
          << (i)
          << "] "
             "["
             "l"
             ": "
          << (l)
          << "] "
             "["
             "ways"
             "["
             "l"
             ": "
          << (l)
          << "] "
             "["
             "i * l"
             ": "
          << (i * l) << "] "
          << ": " << ways[l][i * l]
          << "] "
             "["
             "binom"
             "["
             "cou[i]"
             ": "
          << (cou[i])
          << "] "
             "["
             "l"
             ": "
          << (l) << "] "
          << ": " << binom[cou[i]][l] << "] ";
      if (ways[l][i * l] == binom[cou[i]][l]) {
        (muu() << __FUNCTION__ << "#" << 106 << ": ") << "match";
        ans = l;
        if (l == cou[i]) whole = true;
      }
    }
  }
  if (whole && diff <= 2) ans = n;
  printf("%d\n", ans);
}
