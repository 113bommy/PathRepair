#include <bits/stdc++.h>
using namespace std;
long long n, m;
pair<pair<long long, long long>, pair<long long, long long> > segms[100000];
pair<long long, long long> edges[100000];
map<pair<long long, long long>, long long> num;
vector<long long> G[100000];
pair<long long, long long> pts[100000];
long long X;
long long weight[100000];
long long dX[100000], dY[100000];
pair<long long, long long> mul(pair<long long, long long> a,
                               pair<long long, long long> b) {
  return make_pair(a.first * b.first - a.second * b.second,
                   a.first * b.second + a.second * b.first);
}
long double getY(long long sn) {
  long long al = X - pts[edges[sn].first].first,
            bl = pts[edges[sn].second].first - X;
  return (bl * pts[edges[sn].first].second +
          al * pts[edges[sn].second].second) /
         ((long double)(al + bl));
}
struct vert {
  long long snum;
  vert *lp, *rp;
  long long pr;
  long long delta;
  vert(long long _snum) : snum(_snum) {
    lp = rp = 0;
    pr = rand();
    delta = 0;
  }
};
void norm(vert* root) {
  if (root == nullptr) return;
  if (root->delta != 0) {
    weight[root->snum] += root->delta;
    if (root->lp != 0) {
      root->lp->delta += root->delta;
    }
    if (root->rp != 0) {
      root->rp->delta += root->delta;
    }
    root->delta = 0;
  }
}
void split(vert* root, long double key, vert*& lt, vert*& rt) {
  if (root == 0) {
    lt = rt = 0;
    return;
  }
  norm(root);
  if (getY(root->snum) <= key) {
    split(root->rp, key, root->rp, rt);
    lt = root;
    norm(lt);
  } else {
    split(root->lp, key, lt, root->lp);
    rt = root;
    norm(rt);
  }
}
vert* merge(vert* lt, vert* rt) {
  if (lt == 0) return rt;
  if (rt == 0) return lt;
  norm(lt);
  norm(rt);
  if (lt->pr < rt->pr) {
    lt->rp = merge(lt->rp, rt);
    norm(lt);
    return lt;
  } else {
    rt->lp = merge(lt, rt->lp);
    norm(rt);
    return rt;
  }
}
pair<pair<long long, long long>, long long> sorder[100000];
void normAll(vert* root) {
  if (root == nullptr) return;
  norm(root);
  normAll(root->lp);
  normAll(root->rp);
}
long long getweight(long long u, long long v) {
  if (edges[num[make_pair(u, v)]].first == u) {
    return -weight[num[make_pair(u, v)]];
  } else
    return weight[num[make_pair(u, v)]];
}
long long sign(long long x) { return x > 0 ? 1 : -1; }
long long cross(int i1, int i2) { return dX[i1] * dY[i2] - dY[i1] * dX[i2]; }
int main() {
  srand(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    --u;
    --v;
    edges[i] = make_pair(u, v);
    G[u].push_back(i);
    G[v].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    cin >> pts[i].first >> pts[i].second;
  }
  for (int i = 0; i < m; i++) {
    segms[i] = make_pair(pts[edges[i].first], pts[edges[i].second]);
    if (pts[edges[i].first].first > pts[edges[i].second].first) {
      swap(edges[i].first, edges[i].second);
    }
    dX[i] = pts[edges[i].second].first - pts[edges[i].first].first;
    dY[i] = pts[edges[i].second].second - pts[edges[i].first].second;
    num[make_pair(edges[i].first, edges[i].second)] = i;
    num[make_pair(edges[i].second, edges[i].first)] = i;
  }
  for (int i = 0; i < n; i++) sorder[i] = make_pair(pts[i], i);
  sort(sorder, sorder + n);
  vert* stree = 0;
  for (int i = 0; i < n; i++) {
    long long in = sorder[i].second, ix = sorder[i].first.first,
              iy = sorder[i].first.second;
    X = ix;
    vert *lt, *rt, *mt;
    split(stree, iy - 1e-6, lt, mt);
    split(mt, iy + 1e-6, mt, rt);
    if (rt != 0) {
      rt->delta++;
    }
    normAll(mt);
    vector<long long> sm;
    for (int i = 0; i < G[in].size(); i++)
      if (edges[G[in][i]].first == in && dX[G[in][i]] != 0)
        sm.push_back(G[in][i]);
    sort(sm.begin(), sm.end(), [&](int i1, int i2) -> bool {
      return dX[i1] * dY[i2] - dY[i1] * dX[i2] > 0;
    });
    mt = 0;
    for (int i = 0; i < sm.size(); i++) mt = merge(mt, new vert(sm[i]));
    stree = merge(merge(lt, mt), rt);
  }
  normAll(stree);
  long long q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    long long k;
    cin >> k;
    vector<long long> cyc;
    for (int i = 0; i < k; i++) {
      long long vv;
      cin >> vv;
      cyc.push_back(vv - 1);
    }
    long long sum = 0;
    for (int i = 0; i < cyc.size(); i++) {
      int ii = cyc[i], ip1 = cyc[(i + 1) % cyc.size()];
      sum += pts[ii].first * pts[ip1].second - pts[ii].second * pts[ip1].first;
    }
    if (sum < 0) reverse(cyc.begin(), cyc.end());
    long long cc = 0, delta = 0;
    for (int i = 0; i < cyc.size(); i++) {
      cc += getweight(cyc[i], cyc[(i + 1) % cyc.size()]);
    }
    for (int i = 0; i < cyc.size(); i++) {
      int ip1 = (i + 1) % cyc.size();
      int im = ip1, cc = 0;
      if (pts[cyc[i]].first == pts[cyc[ip1]].first) continue;
      while (pts[cyc[ip1]].first == pts[cyc[im]].first) {
        im = (im + 1) % cyc.size();
        cc++;
      }
      int ipc = cyc[(im - 1 + cyc.size()) % cyc.size()];
      int ii = cyc[i];
      ip1 = cyc[ip1];
      im = cyc[im];
      if (cc == 1) {
        bool b1 = pts[ii].first > pts[ip1].first,
             b2 = pts[ip1].first > pts[im].first;
        if ((b1 || b2) &&
            !(b1 && !b2 &&
              cross(num[make_pair(ii, ip1)], num[make_pair(ip1, im)]) > 0) &&
            !(!b1 && b2 &&
              cross(num[make_pair(ii, ip1)], num[make_pair(ip1, im)]) > 0)) {
          delta++;
        }
      } else {
        if (pts[ipc].second > pts[ip1].second) {
          delta += pts[im].first < pts[ipc].first;
        } else {
          if (pts[ii].first > pts[ip1].first)
            delta += cc;
          else if (pts[ipc].first < pts[im].first)
            delta += cc - 1;
          else
            delta += cc - 1;
        }
      }
    }
    cout << abs(cc) + delta << "\n";
  }
}
