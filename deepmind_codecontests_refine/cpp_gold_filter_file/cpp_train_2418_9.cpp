#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
struct liChao {
  struct line {
    long long k, b;
    long long getY(long long x) { return k * x + b; }
  };
  struct node {
    node *lef = NULL, *righ = NULL;
    line lin = {0, (long long)-1e18};
  };
  node* lc = new node;
  void addLine(line lin, node* nod, long long l = 0, long long r = 1e12) {
    if (r < l) return;
    long long mid = (l + r) / 2;
    bool ansLeft = (lin.getY(l) > nod->lin.getY(l));
    bool ansMid = (lin.getY(mid) > nod->lin.getY(mid));
    if (ansMid) {
      swap(lin, nod->lin);
    }
    if (r == l) {
      return;
    }
    if (ansLeft != ansMid) {
      if (nod->lef == NULL) {
        nod->lef = new node;
      }
      addLine(lin, nod->lef, l, mid);
    } else {
      if (nod->righ == NULL) {
        nod->righ = new node;
      }
      addLine(lin, nod->righ, mid + 1, r);
    }
  }
  long long get(long long x, node* nod, long long l = 0, long long r = 1e12) {
    if (nod == NULL || r < l) return -1e18;
    long long mid = (l + r) / 2;
    if (r == l) {
      return nod->lin.getY(x);
    }
    if (x < mid) {
      return max(get(x, nod->lef, l, mid), nod->lin.getY(x));
    } else {
      return max(get(x, nod->righ, mid + 1, r), nod->lin.getY(x));
    }
  }
};
set<int> g[200001];
int subSize[200001];
int centroid;
long long a[200001];
int dfs1(int v, int p, int n) {
  subSize[v] = 1;
  int maxas = 0;
  for (int i : g[v]) {
    if (i == p) continue;
    subSize[v] += dfs1(i, v, n);
    maxas = max(maxas, subSize[i]);
  }
  maxas = max(maxas, n - subSize[v]);
  if (maxas <= n / 2) {
    centroid = v;
  }
  return subSize[v];
}
vector<pair<long long, long long> > sums1, sums2, sums3;
void getSums(int v, int p, long long dep, long long sum1 = 0,
             long long sum2 = 0, long long sum3 = 0) {
  sum1 += dep * a[v];
  sum3 += a[v];
  sum2 += sum3;
  if (g[v].size() == 1) {
    sums1.push_back({sum1, dep});
    sums2.push_back({sum2, dep});
    sums3.push_back({sum3, dep});
    return;
  }
  for (int i : g[v]) {
    if (i == p) continue;
    getSums(i, v, dep + 1, sum1, sum2, sum3);
  }
}
long long ans = 0;
void solve(int v, int n) {
  dfs1(v, v, n);
  dfs1(centroid, centroid, n);
  {
    liChao tree;
    for (int i : g[centroid]) {
      sums1.clear();
      sums2.clear();
      sums3.clear();
      getSums(i, centroid, 1);
      for (int j = 0; j < sums2.size(); j++) {
        long long sum = sums2[j].first + (sums2[j].second + 1) * a[centroid];
        ans = max(ans, sum + tree.get(sums2[j].second + 1, tree.lc));
        ans = max(ans, sum);
      }
      for (int j = 0; j < sums1.size(); j++) {
        tree.addLine({sums3[j].first, sums1[j].first}, tree.lc);
      }
    }
  }
  {
    liChao tree;
    for (int i : g[centroid]) {
      sums1.clear();
      sums2.clear();
      sums3.clear();
      getSums(i, centroid, 1);
      for (int j = 0; j < sums1.size(); j++) {
        long long sum = sums1[j].first + (sums3[j].first + a[centroid]);
        ans = max(ans, sum + tree.get(sums3[j].first + a[centroid], tree.lc));
        ans = max(ans, sum);
      }
      for (int j = 0; j < sums1.size(); j++) {
        tree.addLine({sums2[j].second, sums2[j].first}, tree.lc);
      }
    }
  }
  int c = centroid;
  for (int i : g[c]) {
    g[i].erase(c);
    solve(i, subSize[i]);
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].insert(v);
    g[v].insert(u);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  solve(1, n);
  cout << ans;
}
