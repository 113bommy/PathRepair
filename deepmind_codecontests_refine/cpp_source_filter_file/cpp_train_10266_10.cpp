#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, i, e, f, g, n, m, k, l, A[500005], T[500005], in[500005],
    out[500005], t, fix[500005], q, r;
long long tree1[500005], tree2[500005], lz[500005];
long long u, v1;
pair<pair<long long, long long>, long long> edge[500005];
vector<pair<long long, long long> > v[500005];
void dfs(long long x, long long y, long long z) {
  A[x] = z;
  t++;
  T[t] = x;
  in[x] = t;
  for (long long i = 0; i < v[x].size(); i++) {
    if (v[x][i].first == y) continue;
    dfs(v[x][i].first, x, z + v[x][i].second);
  }
  out[x] = t;
}
void build1(long long root, long long le, long long ri) {
  if (le == ri) {
    tree1[root] = A[T[le]];
  } else {
    long long mid = (le + ri) / 2;
    build1(root * 2, le, mid);
    build1(root * 2 + 1, mid + 1, ri);
  }
}
void build2(long long root, long long le, long long ri) {
  if (le == ri) {
    tree2[root] = A[T[le]] + fix[T[le]];
  } else {
    long long mid = (le + ri) / 2;
    build2(root * 2, le, mid);
    build2(root * 2 + 1, mid + 1, ri);
    tree2[root] = min(tree2[root * 2], tree2[root * 2 + 1]);
  }
}
void update1(long long root, long long le, long long ri, long long lee,
             long long rii, long long val) {
  if (lee > rii) return;
  if (le == lee && ri == rii) {
    tree1[root] += val;
  } else {
    long long mid = (le + ri) / 2;
    update1(root * 2, le, mid, lee, min(rii, mid), val);
    update1(root * 2 + 1, mid + 1, ri, max(lee, mid + 1), rii, val);
  }
}
void update2(long long root, long long le, long long ri, long long lee,
             long long rii, long long val) {
  if (lee > rii) return;
  if (lee == le && rii == ri) {
    tree2[root] += val;
    lz[root] += val;
  } else {
    tree2[root * 2] += lz[root];
    tree2[root * 2 + 1] += lz[root];
    lz[root * 2] += lz[root];
    lz[root * 2 + 1] += lz[root];
    lz[root] = 0;
    long long mid = (le + ri) / 2;
    update2(root * 2, le, mid, lee, min(rii, mid), val);
    update2(root * 2 + 1, mid + 1, ri, max(lee, mid + 1), rii, val);
    tree2[root] = min(tree2[root * 2], tree2[root * 2 + 1]);
  }
}
long long get1(long long root, long long le, long long ri, long long idx) {
  if (le == ri) return tree1[root];
  long long mid = (le + ri) / 2;
  if (mid >= idx)
    return tree1[root] + get1(root * 2, le, mid, idx);
  else
    return tree1[root] + get1(root * 2 + 1, mid + 1, ri, idx);
}
long long get2(long long root, long long le, long long ri, long long lee,
               long long rii) {
  if (lee > rii) return 1e14;
  if (lee == le && rii == ri) {
    return tree2[root];
  } else {
    tree2[root * 2] += lz[root];
    tree2[root * 2 + 1] += lz[root];
    lz[root * 2] += lz[root];
    lz[root * 2 + 1] += lz[root];
    lz[root] = 0;
    long long mid = (le + ri) / 2;
    return min(get2(root * 2, le, mid, lee, min(rii, mid)),
               get2(root * 2 + 1, mid + 1, ri, max(lee, mid + 1), rii));
  }
}
int main() {
  cin >> n >> q;
  for (long long i = 1; i <= n - 1; i++) {
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
    edge[i].first.first = a;
    edge[i].first.second = b;
    edge[i].second = c;
  }
  dfs(1, 0, 0);
  for (long long i = 1; i <= n - 1; i++) {
    cin >> a >> b >> c;
    fix[a] = c;
    edge[i + n - 1].first.first = a;
    edge[i + n - 1].first.second = b;
    edge[i + n - 1].second = c;
  }
  build1(1, 1, n);
  build2(1, 1, n);
  while (q--) {
    cin >> a >> b >> c;
    if (a == 1) {
      u = edge[b].first.first;
      v1 = edge[b].first.second;
      if (b > n - 1) {
        update2(1, 1, n, in[u], in[u], c - edge[b].second);
      } else {
        if (in[u] > in[v1]) {
          l = in[u];
          r = out[u];
        } else {
          l = in[v1];
          r = out[v1];
        }
        update1(1, 1, n, l, r, c - edge[b].second);
        update2(1, 1, n, l, r, c - edge[b].second);
      }
      edge[b].second = c;
    }
    if (a == 2) {
      if (in[b] <= in[c] && out[c] <= out[b]) {
        cout << get1(1, 1, n, in[c]) - get1(1, 1, n, in[b]) << endl;
        continue;
      } else {
        cout << get1(1, 1, n, in[c]) + get2(1, 1, n, in[b], out[b]) -
                    get1(1, 1, n, in[b])
             << endl;
      }
    }
  }
}
