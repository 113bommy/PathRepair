#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 5;
vector<long long> v1[MAXN];
long long ord[MAXN];
long long arr[MAXN];
long long uord[MAXN];
long long subtreesz[MAXN];
long long timer = 1;
long long dp[MAXN][30];
long long h[MAXN];
long long tree[5 * MAXN];
long long lazy[MAXN];
long long newroot = 1;
long long rootlbound;
long long rootrbound;
void dfs(long long curr, long long par) {
  ord[curr] = timer;
  uord[timer] = curr;
  timer++;
  subtreesz[curr] = 1;
  dp[curr][0] = par;
  for (long long x : v1[curr]) {
    if (x != par) {
      h[x] = h[curr] + 1;
      dfs(x, curr);
      subtreesz[curr] += subtreesz[x];
    }
  }
}
void build(long long curr, long long l, long long r) {
  if (l == r) {
    tree[curr] = arr[uord[l]];
    return;
  }
  long long mid = (l + r) / 2;
  build(2 * curr, l, mid);
  build(2 * curr + 1, mid + 1, r);
  tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}
void update(long long l, long long r, long long ql, long long qr, long long pos,
            long long val) {
  if (lazy[pos]) {
    tree[pos] += (r - l + 1) * lazy[pos];
    if (l != r) {
      lazy[2 * pos] += lazy[pos];
      lazy[2 * pos + 1] += lazy[pos];
    }
    lazy[pos] = 0;
  }
  if (ql > r || qr < l) {
    return;
  }
  if (ql <= l && qr >= r) {
    tree[pos] += (r - l + 1) * val;
    if (l != r) {
      lazy[2 * pos] += val;
      lazy[2 * pos + 1] += val;
    }
    return;
  }
  long long mid = (l + r) / 2;
  update(l, mid, ql, qr, 2 * pos, val);
  update(mid + 1, r, ql, qr, 2 * pos + 1, val);
  tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
}
long long query(long long curr, long long l, long long r, long long ql,
                long long qr) {
  if (lazy[curr]) {
    tree[curr] += (r - l + 1) * lazy[curr];
    if (l != r) {
      lazy[2 * curr] += lazy[curr];
      lazy[2 * curr + 1] += lazy[curr];
    }
    lazy[curr] = 0;
  }
  if (ql > r || qr < l) {
    return 0;
  }
  if (l >= ql && r <= qr) {
    return tree[curr];
  }
  long long mid = (l + r) / 2;
  return query(2 * curr, l, mid, ql, qr) +
         query(2 * curr + 1, mid + 1, r, ql, qr);
}
long long lca(long long x, long long y) {
  if (h[x] > h[y]) {
    swap(x, y);
  }
  for (long long i = 20; i >= 0; i--) {
    if (h[y] - (1 << i) >= h[x]) {
      y = dp[y][i];
    }
  }
  if (x == y) {
    return x;
  }
  for (long long i = 20; i >= 0; i--) {
    if (dp[x][i] != -1 && dp[x][i] != dp[y][i]) {
      x = dp[x][i];
      y = dp[y][i];
    }
  }
  return dp[x][0];
}
long long walk(long long curr, long long steps) {
  for (long long i = 20; i >= 0; i--) {
    if (steps & (1 << i)) {
      curr = dp[curr][i];
    }
  }
  return curr;
}
int main() {
  long long n, q;
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (long long i = 1; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    v1[a].push_back(b);
    v1[b].push_back(a);
  }
  for (long long i = 0; i <= n; i++) {
    for (long long j = 0; j <= 19; j++) {
      dp[i][j] = -1;
    }
  }
  dfs(1, -1);
  build(1, 1, n);
  for (long long i = 1; i <= 19; i++) {
    for (long long j = 1; j <= n; j++) {
      if (dp[j][i - 1] == 0) {
        dp[j][i] = -1;
      } else {
        dp[j][i] = dp[dp[j][i - 1]][i - 1];
      }
    }
  }
  newroot = 1;
  rootlbound = ord[1];
  rootrbound = ord[1] + subtreesz[1] - 1;
  while (q--) {
    long long t;
    cin >> t;
    if (t == 1) {
      cin >> newroot;
      rootlbound = ord[newroot];
      rootrbound = ord[newroot] + subtreesz[newroot] - 1;
    } else if (t == 2) {
      long long u, v, c;
      cin >> u >> v >> c;
      long long temp = 0;
      long long anc;
      if (ord[u] >= rootlbound && ord[u] <= rootrbound) {
        temp++;
      }
      if (ord[v] >= rootlbound && ord[v] <= rootrbound) {
        temp++;
      }
      if (temp == 2) {
        anc = lca(u, v);
      } else if (temp == 1) {
        anc = newroot;
      } else {
        long long x = lca(u, v);
        long long y = lca(u, newroot);
        long long z = lca(v, newroot);
        if (h[x] > h[y]) {
          anc = x;
        } else {
          anc = y;
        }
        if (h[z] > h[anc]) {
          anc = z;
        }
      }
      if (anc == newroot) {
        update(1, n, 1, n, 1, c);
      } else if (rootlbound < ord[anc] && rootrbound >= ord[anc]) {
        update(1, n, ord[anc], ord[anc] + subtreesz[anc] - 1, 1, c);
      } else if (ord[anc] < ord[newroot] &&
                 ord[newroot] <= ord[anc] + subtreesz[anc] - 1) {
        update(1, n, 1, n, 1, c);
        long long diff = h[newroot] - h[anc];
        long long undo = walk(newroot, diff - 1);
        update(1, n, ord[undo], ord[undo] + subtreesz[undo] - 1, 1, -c);
      } else {
        update(1, n, ord[anc], ord[anc] + subtreesz[anc] - 1, 1, c);
      }
    } else {
      long long origin;
      cin >> origin;
      if (origin == newroot) {
        cout << query(1, 1, n, 1, n) << endl;
      } else if (rootlbound < ord[origin] && ord[origin] <= rootrbound) {
        cout << query(1, 1, n, ord[origin], ord[origin] + subtreesz[origin] - 1)
             << endl;
      } else if (ord[origin] < ord[newroot] &&
                 ord[newroot] <= ord[origin] + subtreesz[origin] - 1) {
        long long ans = query(1, 1, n, 1, n);
        long long diff = h[newroot] - h[origin];
        long long undo = walk(newroot, diff - 1);
        cout << ans - query(1, 1, n, ord[undo], ord[undo] + subtreesz[undo] - 1)
             << endl;
      } else {
        cout << query(1, 1, n, ord[origin], ord[origin] + subtreesz[origin] - 1)
             << endl;
      }
    }
  }
}
