#include <bits/stdc++.h>
using namespace std;
vector<long long> p = {1, 2, 3, 5, 9, 17};
vector<long long> pot;
const long long MOD = 998244353;
long long fpow(long long b, long long e) {
  long long res = 1;
  while (e) {
    if (e & 1) res = res * b % MOD;
    b = b * b % MOD, e >>= 1;
  }
  return res;
}
long long k, a, h;
vector<long long> getw(long long n, long long mk) {
  vector<long long> v, vn, res(n);
  for (int i = 0, ggdem = n; i < ggdem; ++i) v.push_back(i);
  long long va = 0, ta = 0;
  while (((int)v.size()) > 1) {
    for (int i = 0, ggdem = ((int)v.size()) / 2; i < ggdem; ++i) {
      if ((1ll << va) & mk) {
        vn.push_back(v[2 * i]);
        res[v[2 * i + 1]] = ta;
      } else {
        vn.push_back(v[2 * i + 1]);
        res[v[2 * i]] = ta;
      }
      va++;
    }
    ta++;
    v = vn;
    vn.clear();
  }
  res[v[0]] = ta;
  return res;
}
long long calch(long long st, long long n, long long mk, long long posp,
                long long w) {
  auto g = getw(n, mk);
  for (int i = 0, ggdem = ((int)g.size()); i < ggdem; ++i)
    g[i] = p[posp - g[i]];
  if (w) {
    for (int i = 0, ggdem = ((int)g.size()); i < ggdem; ++i) {
      if (g[i] == 2) g[i] = 1;
    }
  }
  long long res = 0;
  for (int i = 0, ggdem = n; i < ggdem; ++i) {
    res = (res + (st + i) * pot[g[i]]) % MOD;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> k >> a >> h;
  for (int i = 0, ggdem = 20; i < ggdem; ++i) pot.push_back(fpow(a, i));
  long long n = (1ll << k);
  if (k <= 3) {
    for (int i = 0, ggdem = (1ll << (n - 1)); i < ggdem; ++i) {
      if (calch(1, n, i, k, 0) == h) {
        auto res = getw(n, i);
        for (auto i : res) cout << p[k - i] << " ";
        cout << "\n";
        return 0;
      }
    }
    cout << "-1\n";
  } else {
    long long nn = n / 2;
    set<pair<long long, long long>> st[2];
    for (int i = 0, ggdem = (1ll << (nn - 1)); i < ggdem; ++i) {
      st[0].insert({calch(nn + 1, nn, i, k, 0), i});
      st[1].insert({calch(nn + 1, nn, i, k, 1), i});
    }
    for (int i = 0, ggdem = (1ll << (nn - 1)); i < ggdem; ++i) {
      auto c0 = calch(1, nn, i, k, 0);
      auto it0 = st[1].lower_bound(
          pair<long long, long long>({(h - c0 + MOD) % MOD, -1}));
      if (it0 != st[1].end() && it0->first == (h - c0 + MOD) % MOD) {
        auto res = getw(nn, i);
        for (auto i : res) {
          cout << p[k - i] << " ";
        }
        res = getw(nn, it0->second);
        for (auto i : res) {
          if (p[k - i] > 2)
            cout << p[k - i] << " ";
          else
            cout << "1 ";
        }
        cout << "\n";
        return 0;
      }
      auto c1 = calch(1, nn, i, k, 1);
      auto it1 = st[0].lower_bound(
          pair<long long, long long>({(h - c1 + MOD) % MOD, -1}));
      if (it1 != st[0].end() && it1->first == (h - c1 + MOD) % MOD) {
        auto res = getw(nn, i);
        for (auto i : res) {
          if (p[k - i] > 2)
            cout << p[k - i] << " ";
          else
            cout << "1 ";
        }
        res = getw(nn, it1->second);
        for (auto i : res) {
          cout << p[k - i] << " ";
        }
        cout << "\n";
        return 0;
      }
    }
    cout << "-1\n";
  }
  return 0;
}
