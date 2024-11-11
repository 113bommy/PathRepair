#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
const int mod = 998244353;
int n, m;
int mul = 1;
inline void Add(int& x, int y) {
  x += y;
  if (x >= mod) {
    x -= mod;
  }
}
vi SolveDp(int rsize, vll basis) {
  debug() << " ["
          << "rsize"
             ": "
          << (rsize) << "] "
          << " ["
          << "basis"
             ": "
          << (basis) << "] ";
  vector<vi> dp[2];
  int tsz = ((int)(basis).size());
  for (int i = 0; i < 2; ++i) {
    dp[i].resize(tsz + 1, vi(1 << rsize));
  }
  dp[0][0][0] = 1;
  for (int i = 0; i < ((int)(basis).size()); ++i) {
    int from = i % 2;
    int to = (i + 1) % 2;
    for (int row = 0; row <= tsz; ++row) {
      fill((dp[to][row]).begin(), (dp[to][row]).end(), 0);
    }
    for (int cnt = 0; cnt <= i; ++cnt) {
      for (int mask = 0; mask < (1 << rsize); ++mask) {
        int src = dp[from][cnt][mask];
        if (!src) {
          continue;
        }
        Add(dp[to][cnt][mask], src);
        Add(dp[to][cnt + 1][mask ^ basis[i]], src);
      }
    }
  }
  vi ans(m + 1);
  int last = ((int)(basis).size()) % 2;
  for (int cnt = 0; cnt <= tsz; ++cnt) {
    for (int mask = 0; mask < (1 << rsize); ++mask) {
      Add(ans[cnt + __builtin_popcount(mask)], dp[last][cnt][mask]);
    }
  }
  return ans;
}
vi SolveBrute(int, vll basis) {
  vi ans(m + 1);
  int tsz = ((int)(basis).size());
  for (int mask = 0; mask < (1 << tsz); ++mask) {
    ll rem = 0;
    for (int i = 0; i < tsz; ++i) {
      if ((mask >> i) & 1) {
        rem ^= basis[i];
      }
    }
    ++ans[__builtin_popcount(mask) + __builtin_popcount(rem)];
  }
  return ans;
}
void Out(vi ans) {
  for (int val : ans) {
    cout << ((ll)val * mul) % mod << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  cin >> n >> m;
  vll basis(m, -1);
  for (int i = 0; i < n; ++i) {
    ll val;
    cin >> val;
    for (int b = 0; b < m; ++b) {
      if (basis[b] != -1 && ((val >> b) & 1)) {
        val ^= basis[b];
      }
    }
    if (!val) {
      mul = (mul * 2) % mod;
    } else {
      int bit = 0;
      while (!((val >> bit) & 1)) {
        ++bit;
      }
      assert(basis[bit] == -1);
      for (int j = 0; j < m; ++j) {
        if (basis[j] != -1 && (basis[j] >> bit) & 1) {
          basis[j] ^= val;
        }
      }
      basis[bit] = val;
    }
    debug() << " ["
            << "i"
               ": "
            << (i) << "] "
            << " ["
            << "basis"
               ": "
            << (basis) << "] ";
  }
  vi nonbits;
  for (int i = 0; i < m; ++i) {
    if (basis[i] == -1) {
      nonbits.push_back(i);
    }
  }
  int rsize = ((int)(nonbits).size());
  vll comp_basis;
  for (int i = 0; i < m; ++i) {
    if (basis[i] != -1) {
      ll new_val = 0;
      for (int j = 0; j < ((int)(nonbits).size()); ++j) {
        int b = nonbits[j];
        new_val |= (((basis[i] >> b) & 1) << j);
      }
      comp_basis.push_back(new_val);
    }
  }
  debug() << " ["
          << "rsize"
             ": "
          << (rsize) << "] "
          << " ["
          << "comp_basis"
             ": "
          << (comp_basis) << "] ";
  if (rsize <= 16) {
    Out(SolveDp(rsize, comp_basis));
  } else {
    Out(SolveBrute(rsize, comp_basis));
  }
}
