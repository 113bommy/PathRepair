#include <bits/stdc++.h>
const long long MAX_N = 3e5 + 100;
const long long MOD = 1e9 + 7;
using namespace std;
vector<int> g[MAX_N];
vector<int> e;
int h[MAX_N];
int rm[MAX_N][50];
int mr[MAX_N][50];
int qr[MAX_N][50];
int f[MAX_N];
int n, q;
void dfs(int v) {
  f[v] = e.size();
  e.push_back(h[v]);
  for (auto x : g[v]) {
    h[x] = h[v] + 1;
    dfs(x);
    e.push_back(h[v]);
  }
}
int gt1(int l, int r) {
  if (r < l) return 0;
  if (r == l) return mr[l][0];
  int lg = (int)log2(r - l + 1);
  int x = r - (1ll << lg) + 1;
  if (f[mr[l][lg]] > f[mr[x][lg]])
    return mr[l][lg];
  else
    return mr[x][lg];
}
int gt2(int l, int r) {
  if (r < l) return 0;
  if (r == l) return qr[l][0];
  int lg = (int)log2(r - l + 1);
  int x = r - (1ll << lg) + 1;
  if (f[qr[l][lg]] < f[qr[x][lg]])
    return qr[l][lg];
  else
    return qr[x][lg];
}
int gt3(int l, int r) {
  if (r < l) return 0;
  if (r == l) return rm[l][0];
  int lg = (int)log2(r - l + 1);
  int x = r - (1ll << lg) + 1;
  if (rm[l][lg] < rm[x][lg])
    return rm[l][lg];
  else
    return rm[x][lg];
}
int main() {
  cin >> n >> q;
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    p--;
    g[p].push_back(i);
  }
  dfs(0);
  for (int i = 0; i < e.size(); ++i) rm[i][0] = e[i];
  for (int i = 1; i <= log2(e.size()); ++i) {
    for (int j = 0; j <= (e.size() - (1ll << i)); ++j) {
      rm[j][i] = min(rm[j][i - 1], rm[j + (1ll << (i - 1))][i - 1]);
    }
  }
  for (int i = 0; i < n; ++i) mr[i][0] = qr[i][0] = i;
  for (int i = 1; i <= log2(n); ++i) {
    for (int j = 0; j <= (n - (1ll << i)); ++j) {
      if (f[mr[j][i - 1]] > f[mr[j + (1ll << (i - 1))][i - 1]])
        mr[j][i] = mr[j][i - 1];
      else
        mr[j][i] = mr[j + (1ll << (i - 1))][i - 1];
    }
  }
  for (int i = 1; i <= log2(n); ++i) {
    for (int j = 0; j <= (n - (1ll << i)); ++j) {
      if (f[qr[j][i - 1]] < f[qr[j + (1ll << (i - 1))][i - 1]])
        qr[j][i] = qr[j][i - 1];
      else
        qr[j][i] = qr[j + (1ll << (i - 1))][i - 1];
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int u = gt1(l, r);
    int v = gt2(l, r);
    int w1, z1;
    if (f[gt1(l, u - 1)] > f[gt1(u + 1, r)])
      z1 = gt1(l, u - 1);
    else
      z1 = gt1(u + 1, r);
    if (f[gt2(l, u - 1)] < f[gt2(u + 1, r)])
      w1 = gt2(l, u - 1);
    else
      w1 = gt2(u + 1, r);
    if (u == r) {
      z1 = gt1(l, r - 1);
      w1 = gt2(l, r - 1);
    }
    if (u == l) {
      z1 = gt1(l + 1, r);
      w1 = gt2(l + 1, r);
    }
    int w2, z2;
    if (f[gt1(l, v - 1)] > f[gt1(v + 1, r)])
      z2 = gt1(l, v - 1);
    else
      z2 = gt1(v + 1, r);
    if (f[gt2(l, v - 1)] < f[gt2(v + 1, r)])
      w2 = gt2(l, v - 1);
    else
      w2 = gt2(v + 1, r);
    if (v == r) {
      z2 = gt1(l, r - 1);
      w2 = gt2(l, r - 1);
    }
    if (v == l) {
      z2 = gt1(l + 1, r);
      w2 = gt2(l + 1, r);
    }
    if (gt3(f[w1], f[z1]) > gt3(f[w2], f[z2]))
      cout << u + 1 << " " << gt3(f[w1], f[z1]) << "\n";
    else
      cout << v + 1 << " " << gt3(f[w2], f[z2]) << "\n";
  }
  return 0;
}
