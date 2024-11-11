#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll L = 19;
const ll N = 1 << L;
ll n;
ll per[N];
ll inv[N];
vector<ll> g[N];
ll l2[N];
ll st[L][N];
ll tl[N];
ll tr[N];
ll ti;
ll argmin(ll i, ll j) { return tl[i] < tl[j] ? i : j; }
void predfs(ll v) {
  tl[v] = ti;
  st[0][ti++] = v;
  for (ll u : g[v]) {
    predfs(u);
    st[0][ti++] = v;
  }
  tr[v] = ti;
}
ll lca(ll v, ll u) {
  ll l = min(tl[v], tl[u]);
  ll r = max(tl[v], tl[u]) + 1;
  ll i = l2[r - l];
  return argmin(st[i][l], st[i][r - (1 << i)]);
}
using pii = pair<ll, ll>;
const pii BAD = {-1, -1};
const pii NONE = {-2, -2};
pii tree[2 * N];
bool anc(ll v, ll u) { return tl[v] <= tl[u] && tr[u] <= tr[v]; }
bool vert(ll v, ll first, ll second) {
  assert(anc(second, first));
  return anc(second, v) && (anc(first, v) || anc(v, first));
}
pii comb(pii a, pii b) {
  if (a == BAD || b == BAD) {
    return BAD;
  }
  if (a == NONE) return b;
  if (b == NONE) return a;
  ll v = a.first, u = a.first;
  if (tl[v] < tl[a.second]) v = a.second;
  if (tl[v] < tl[b.first]) v = b.first;
  if (tl[v] < tl[b.second]) v = b.second;
  if (tr[u] > tr[a.second]) u = a.second;
  if (tr[u] > tr[b.first]) u = b.first;
  if (tr[u] > tr[b.second]) u = b.second;
  if (v == u) {
    v = a.first;
    if (tl[v] > tl[a.second]) v = a.second;
    if (tl[v] > tl[b.first]) v = b.first;
    if (tl[v] > tl[b.second]) v = b.second;
  }
  ll l = lca(v, u);
  if (!vert(a.first, v, l) && !vert(a.first, u, l)) return BAD;
  if (!vert(a.second, v, l) && !vert(a.second, u, l)) return BAD;
  if (!vert(b.first, v, l) && !vert(b.first, u, l)) return BAD;
  if (!vert(b.second, v, l) && !vert(b.second, u, l)) return BAD;
  return {v, u};
}
void update(ll v) {
  for (v /= 2; v > 0; v /= 2) {
    tree[v] = comb(tree[v + v], tree[v + v + 1]);
  }
}
pii query(ll l, ll r) {
  pii res = NONE;
  for (l += N, r += N; l <= r; l /= 2, r /= 2) {
    if (l % 2 == 1) {
      res = comb(res, tree[l++]);
    }
    if (r % 2 == 0) {
      res = comb(res, tree[r--]);
    }
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (ll i = 2; i < N; ++i) {
    l2[i] = l2[i / 2] + 1;
  }
  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> per[i];
    inv[per[i]] = i;
  }
  for (ll p, i = 1; i < n; ++i) {
    cin >> p;
    --p;
    g[p].push_back(i);
  }
  predfs(0);
  for (ll i = 1; i < L; ++i) {
    for (ll j = 0; j + (1 << i) <= N; ++j) {
      st[i][j] = argmin(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }
  for (ll i = 0; i < n; ++i) {
    ll v = inv[i];
    tree[N + i] = {v, v};
  }
  for (ll i = N - 1; i > 0; --i) {
    tree[i] = comb(tree[i + i], tree[i + i + 1]);
  }
  ll q;
  cin >> q;
  while (q--) {
    ll tp;
    cin >> tp;
    if (tp == 1) {
      ll i, j;
      cin >> i >> j;
      --i, --j;
      swap(per[i], per[j]);
      swap(inv[per[i]], inv[per[j]]);
      ll first = per[i], second = per[j];
      swap(tree[N + first], tree[N + second]);
      update(N + first), update(N + second);
    } else {
      ll lef = 0, rig = n;
      while (rig - lef > 1) {
        ll mid = (lef + rig) / 2;
        if (query(0, mid) != BAD) {
          lef = mid;
        } else {
          rig = mid;
        }
      }
      cout << rig << "\n";
    }
  }
  return 0;
}
