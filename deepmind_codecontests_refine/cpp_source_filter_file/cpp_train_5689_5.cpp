#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  char c;
  int f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') f = -1;
  x = (c & 15);
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + (c & 15);
  x *= f;
}
const int mod = 998244353, inv2 = (mod + 1) / 2;
int n, m, i, j, inv[35], c[35][35], a[35];
int qp(int x, int y) {
  int z = 1;
  while (y) {
    if (y & 1) {
      z = 1ll * x * z % mod;
    }
    x = 1ll * x * x % mod;
    y /= 2;
  }
  return z;
}
struct func {
  int l, r;
  vector<int> xs;
};
bool operator<(func x, func y) { return x.l < y.l; }
vector<func> s, nxt;
vector<int> intg(int l, int r) {
  vector<int> ans, tmp;
  int i, j, k;
  for (i = 0; i < s.size(); i++) {
    tmp.clear();
    tmp.resize(s[i].xs.size() + 1);
    if (s[i].l <= l - 1000000) {
      if (s[i].r <= l - 1000000) {
        continue;
      } else if (l - 1000000 < s[i].r && s[i].r <= r - 1000000 ||
                 r - 1000000 < s[i].r && s[i].r <= l) {
        for (j = 1; j <= s[i].xs.size(); j++) {
          for (k = 0; k <= j; k++) {
            {
              tmp[k] -= (1ll * inv[j] * s[i].xs[j - 1] % mod * c[j][k] % mod *
                         qp(mod - 1000000, j - k) % mod);
              if (tmp[k] < 0) tmp[k] += mod;
            }
          }
          {
            tmp[0] +=
                (1ll * inv[j] * s[i].xs[j - 1] % mod * qp(s[i].r, j) % mod);
            if (tmp[0] >= mod) tmp[0] -= mod;
          }
        }
      } else
        exit(-1);
    } else if (l - 1000000 < s[i].l && s[i].l <= r - 1000000 ||
               r - 1000000 < s[i].l && s[i].l <= l) {
      if (l - 1000000 < s[i].r && s[i].r <= r - 1000000) {
        exit(-1);
      } else if (r - 1000000 < s[i].r && s[i].r <= l) {
        for (j = 1; j <= s[i].xs.size(); j++) {
          {
            tmp[0] -=
                (1ll * inv[j] * s[i].xs[j - 1] % mod * qp(s[i].l, j) % mod);
            if (tmp[0] < 0) tmp[0] += mod;
          }
          {
            tmp[0] +=
                (1ll * inv[j] * s[i].xs[j - 1] % mod * qp(s[i].r, j) % mod);
            if (tmp[0] >= mod) tmp[0] -= mod;
          }
        }
      } else if (l < s[i].r) {
        for (j = 1; j <= s[i].xs.size(); j++) {
          {
            tmp[0] -=
                (1ll * inv[j] * s[i].xs[j - 1] % mod * qp(s[i].l, j) % mod);
            if (tmp[0] < 0) tmp[0] += mod;
          }
          {
            tmp[j] += (1ll * inv[j] * s[i].xs[j - 1] % mod);
            if (tmp[j] >= mod) tmp[j] -= mod;
          }
        }
      }
    } else
      continue;
    while (ans.size() < tmp.size()) ans.push_back(0);
    for ((j) = 0; (j) < (tmp.size()); (j)++) {
      ans[j] += (tmp[j]);
      if (ans[j] >= mod) ans[j] -= mod;
    }
  }
  return ans;
}
int main() {
  inv[1] = 1;
  for ((i) = (2); (i) <= (32); (i)++) {
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  }
  c[0][0] = 1;
  for ((i) = 1; (i) <= (32); (i)++) {
    c[i][0] = 1;
    for ((j) = 1; (j) <= (i); (j)++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  cin >> n;
  for ((i) = 1; (i) <= (n); (i)++) {
    double x;
    cin >> x;
    a[i] = x * 1000000;
    if (a[i] == 0) {
      puts("0");
      return 0;
    }
    a[i] = min(a[i], a[i - 1] + 1000000);
  }
  vector<int> tmp;
  tmp.push_back(1);
  s.push_back((func){0, a[1], tmp});
  for ((i) = (2); (i) <= (n); (i)++) {
    vector<int> all;
    nxt.clear();
    for (__typeof((s).begin()) it = (s).begin(); it != (s).end(); it++) {
      all.push_back(it->l);
      all.push_back(it->r);
      all.push_back(it->l + 1000000);
      all.push_back(it->r + 1000000);
    }
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    while (all.back() > a[i]) all.pop_back();
    if (all.back() != a[i]) all.push_back(a[i]);
    for (j = 1; j < all.size(); j++) {
      nxt.push_back((func){all[j - 1], all[j], intg(all[j - 1], all[j])});
    }
    s = nxt;
  }
  int ans = 0;
  for (__typeof((s).begin()) it = (s).begin(); it != (s).end(); it++) {
    for ((i) = 1; (i) <= (it->xs.size()); (i)++) {
      {
        ans += (1ll * inv[i] * it->xs[i - 1] % mod * qp(it->r, i) % mod);
        if (ans >= mod) ans -= mod;
      }
      {
        ans -= (1ll * inv[i] * it->xs[i - 1] % mod * qp(it->l, i) % mod);
        if (ans < 0) ans += mod;
      }
    }
  }
  printf("%d\n", 1ll * ans * qp(qp(1000000, mod - 2), n) % mod);
  return 0;
}
