#include <bits/stdc++.h>
using namespace std;
struct info {
  long long tp, ii, jj, qn, nxt, prv;
} d;
long long cn[1002][1002], n, m;
long long rev[1003], cnt[1003], tot, an[100003];
long long vis[100002];
long long par[100002];
vector<info> v[100005];
long long go(long long nd, long long pr, long long j, long long dec) {
  vis[nd] = 1;
  long long s, i, r, is, dtot;
  info cd;
  an[nd] = tot;
  dtot = tot;
  if (v[nd].size() == 0) {
    cd = v[pr][j];
    if (cd.tp == 1) {
      if (dec) {
        cn[cd.ii][cd.jj] = cn[cd.ii][cd.jj] ^ 1LL;
        cnt[cd.ii]--;
        tot--;
      }
    } else if (cd.tp == 2) {
      if (dec) {
        cn[cd.ii][cd.jj] = cn[cd.ii][cd.jj] ^ 1LL;
        cnt[cd.ii]++;
        tot++;
      }
    } else if (cd.tp == 3) {
      rev[cd.ii]--;
      tot -= cnt[cd.ii];
      cnt[cd.ii] = m - cnt[cd.ii];
      tot += cnt[cd.ii];
    }
    return 1;
  }
  for (i = 0; i <= v[nd].size() - 1; i++) {
    is = 0;
    cd = v[nd][i];
    if (cd.tp == 4) {
      an[cd.qn] = dtot;
      continue;
    }
    if (cd.tp == 1) {
      if (rev[cd.ii] % 2) {
        if (cn[cd.ii][cd.jj]) {
          cn[cd.ii][cd.jj] = 0;
          is = 1;
          tot++;
          cnt[cd.ii]++;
        }
      } else {
        if (!cn[cd.ii][cd.jj]) {
          cn[cd.ii][cd.jj] = 1;
          is = 1;
          tot++;
          cnt[cd.ii]++;
        }
      }
      r = go(cd.qn, nd, i, is);
    } else if (cd.tp == 2) {
      if (rev[cd.ii] % 2) {
        if (!cn[cd.ii][cd.jj]) {
          is = 1;
          cn[cd.ii][cd.jj] = 1;
          cnt[cd.ii]--;
          tot--;
        }
      } else {
        if (cn[cd.ii][cd.jj]) {
          cn[cd.ii][cd.jj] = 0;
          is = 1;
          tot--;
          cnt[cd.ii]--;
        }
      }
      r = go(cd.qn, nd, i, is);
    } else if (cd.tp == 3) {
      rev[cd.ii]++;
      tot -= cnt[cd.ii];
      cnt[cd.ii] = m - cnt[cd.ii];
      tot += cnt[cd.ii];
      r = go(cd.qn, nd, i, dec);
    }
  }
  if (pr == -1) return 1;
  cd = v[pr][j];
  if (cd.tp == 1) {
    if (dec) {
      cn[cd.ii][cd.jj] = cn[cd.ii][cd.jj] ^ 1LL;
      cnt[cd.ii]--;
      tot--;
    }
  } else if (cd.tp == 2) {
    if (dec) {
      cn[cd.ii][cd.jj] = cn[cd.ii][cd.jj] ^ 1LL;
      cnt[cd.ii]++;
      tot++;
    }
  } else if (cd.tp == 3) {
    rev[cd.ii]--;
    tot -= cnt[cd.ii];
    cnt[cd.ii] = m - cnt[cd.ii];
    tot += cnt[cd.ii];
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long int i, j, x, cnt = 0, y, k, g, flg, q, cnd;
  cin >> n >> m >> q;
  cnd = 0;
  for (i = 1; i <= q; i++) {
    par[i] = -1;
  }
  for (i = 1; i <= q; i++) {
    cin >> k;
    d.tp = k;
    if (k == 4) {
      cin >> y;
      cnd = y;
      d.nxt = -1;
      d.qn = i;
      if (par[y] != -1)
        cnd = par[i] = par[y];
      else
        cnd = par[i] = y;
      v[cnd].push_back(d);
    } else if (k == 1 || k == 2) {
      cin >> x >> y;
      d.ii = x;
      d.jj = y;
      d.qn = i;
      d.prv = cnd;
      v[cnd].push_back(d);
      cnd = i;
    } else if (k == 3) {
      cin >> x;
      d.ii = x;
      d.qn = i;
      d.prv = cnd;
      v[cnd].push_back(d);
      cnd = i;
    }
  }
  x = go(0, -1, 0, 0);
  for (i = 1; i <= q; i++) {
    cout << an[i] << endl;
  }
}
