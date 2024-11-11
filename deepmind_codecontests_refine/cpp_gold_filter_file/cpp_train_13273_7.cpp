#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
long long pw(long long a, long long b) {
  long long ret = 1;
  long long mul = a;
  while (b > 0) {
    if (b & 1) ret = (ret * mul);
    mul = (mul * mul);
    b /= 2;
  }
  return ret;
}
long long to_int(string s) {
  long long ret = 0;
  for (int(i) = (0); (i) < (s.size()); (i)++) {
    ret += pw(10, s.size() - i - 1) * (long long)(s[i] - '0');
  }
  return ret;
}
const int MAXN = 5e4 + 54;
struct ed {
  int s, e, c, l, st;
};
int n, m, cnt[MAXN], d2[MAXN];
ed e[MAXN];
vector<int> adj[MAXN], ce[MAXN], cs;
int par[MAXN], rnk[MAXN], pr[MAXN];
pair<int, int> get(int v) {
  if (par[v] != v) {
    pair<int, int> tmp = get(par[v]);
    par[v] = tmp.first, pr[v] ^= tmp.second;
  }
  return {par[v], pr[v]};
}
bool uni(int a, int b) {
  pair<int, int> aa = get(a), bb = get(b);
  if (aa.first == bb.first and aa.second == bb.second) return 0;
  if (aa.first == bb.first) return 1;
  par[bb.first] = aa.first;
  rnk[aa.first] += (rnk[aa.first] == rnk[bb.first]);
  pr[bb.first] ^= aa.second ^ bb.second ^ 1;
  return 1;
}
bool stst(int id, int st) {
  if (st == 1) {
    if (e[id].st == 0) return 0;
    if (e[id].st == 1) return 1;
    e[id].st = 1;
    int u = e[id].s, v = e[id].e, c = e[id].c;
    if (d2[u] == c) {
      for (int cid : adj[u]) {
        if (cid == id) continue;
        if (e[cid].c == c) {
          if (!stst(cid, 0)) return 0;
        }
      }
    }
    if (d2[v] == c) {
      for (int cid : adj[v]) {
        if (cid == id) continue;
        if (e[cid].c == c) {
          if (!stst(cid, 0)) return 0;
        }
      }
    }
  } else {
    if (e[id].st == 1) return 0;
    if (e[id].st == 0) return 1;
    e[id].st = 0;
    int u = e[id].s, v = e[id].e, c = e[id].c;
    for (int cid : adj[u]) {
      if (cid == id) continue;
      if (!stst(cid, 1)) return 0;
    }
    for (int cid : adj[v]) {
      if (cid == id) continue;
      if (!stst(cid, 1)) return 0;
    }
  }
  return 1;
}
bool chk(int M) {
  for (int(i) = (0); (i) < (m); (i)++) e[i].st = -1;
  for (int(i) = (0); (i) < (m); (i)++) {
    if (e[i].l > M)
      if (!stst(i, 1)) return 0;
  }
  for (int(v) = (0); (v) < (n); (v)++) {
    if (d2[v]) {
      for (int id : adj[v]) {
        if (e[id].c != d2[v])
          if (!stst(id, 1)) return 0;
      }
    }
  }
  for (int(v) = (0); (v) < (n); (v)++) {
    if (d2[v]) continue;
    for (int id : adj[v]) {
      if (e[id].st == -1) {
        if (!stst(id, 1)) return 0;
      }
    }
  }
  for (int(v) = (0); (v) < (n); (v)++) {
    if (d2[v]) {
      for (int id : adj[v]) {
        if (e[id].c == d2[v]) {
          stst(id, 1);
          break;
        }
      }
    }
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  for (int(i) = (0); (i) < (MAXN); (i)++) par[i] = i;
  cin >> n >> m;
  for (int(i) = (0); (i) < (m); (i)++) {
    cin >> e[i].s >> e[i].e >> e[i].c >> e[i].l;
    e[i].s--, e[i].e--;
    cs.push_back(e[i].c);
    adj[e[i].s].push_back(i), adj[e[i].e].push_back(i);
  }
  sort((cs).begin(), (cs).end());
  cs.resize(unique((cs).begin(), (cs).end()) - cs.begin());
  for (int(i) = (0); (i) < (m); (i)++)
    e[i].c = lower_bound((cs).begin(), (cs).end(), e[i].c) - cs.begin() + 1,
    ce[e[i].c].push_back(i);
  bool fl = 1;
  for (int(i) = (1); (i) < (MAXN); (i)++) {
    for (int id : ce[i]) {
      cnt[e[id].s]++;
      cnt[e[id].e]++;
      fl &= uni(e[id].s, e[id].e);
    }
    for (int id : ce[i]) {
      par[e[id].s] = e[id].s, par[e[id].e] = e[id].e;
      rnk[e[id].s] = pr[e[id].s] = rnk[e[id].e] = pr[e[id].e] = 0;
      fl &= (cnt[e[id].s] <= 2) & (cnt[e[id].e] <= 2) &
            (cnt[e[id].s] < 2 or !d2[e[id].s]) &
            (cnt[e[id].e] < 2 or !d2[e[id].e]);
      if (cnt[e[id].s] >= 2) d2[e[id].s] = i;
      if (cnt[e[id].e] >= 2) d2[e[id].e] = i;
      cnt[e[id].s] = cnt[e[id].e] = 0;
    }
    if (!fl) break;
  }
  if (!fl) {
    cout << "No"
         << "\n";
    return 0;
  }
  int l = -1, r = 1e9 + 19;
  while (r - l > 1) {
    int M = (l + r) / 2;
    if (chk(M))
      r = M;
    else
      l = M;
  }
  if (r >= 1e9)
    cout << "No"
         << "\n";
  else {
    chk(r);
    int ans = 0;
    for (int(i) = (0); (i) < (m); (i)++) ans += (e[i].st == 0);
    cout << "Yes"
         << "\n"
         << r << " " << ans << "\n";
    for (int(i) = (0); (i) < (m); (i)++)
      if (!e[i].st) cout << i + 1 << " ";
    cout << "\n";
  }
}
