#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int a[maxn], p[maxn], ans[maxn];
int dfs[2 * maxn][2], freq[maxn], psum[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
      cin >> p[i];
      --p[i];
    }
    vector<vector<int>> g(n);
    vector<vector<vector<int>>> qs(n);
    for (int i = 0; i < n - 1; ++i) g[p[i]].push_back(i + 1);
    for (int i = 0; i < q; ++i) {
      int v, l, k;
      cin >> v >> l >> k;
      --v;
      vector<int> q;
      q.push_back(i);
      q.push_back(l);
      q.push_back(k);
      qs[v].push_back(q);
    }
    int pt = 0;
    vector<unordered_set<int>> sets(n + 2);
    for (int i = 0; i < n; ++i) sets[0].insert(i);
    sets[n + 1].insert(-2);
    for (int i = 1; i <= n + 1; ++i) psum[i] = n;
    dfs[pt][0] = 0;
    dfs[pt++][1] = 0;
    while (pt) {
      int i = dfs[--pt][0], stage = dfs[pt][1];
      sets[freq[a[i]]].erase(a[i]);
      if (stage == 0) {
        sets[++freq[a[i]]].insert(a[i]);
        --psum[freq[a[i]]];
        for (vector<int> qry : qs[i]) {
          int id = qry[0], l = qry[1], k = qry[2] + psum[l];
          int bucket = n + 1;
          for (int l = 1, r = n + 1; l <= r;) {
            int m = l + (r - l) / 2;
            if (psum[m] >= k) {
              bucket = r = m - 1;
            } else {
              l = m + 1;
            }
          }
          for (int num : sets[bucket]) {
            ans[id] = num + 1;
            break;
          }
        }
        dfs[pt][0] = i;
        dfs[pt++][1] = 1;
        for (int j : g[i]) {
          dfs[pt][0] = j;
          dfs[pt++][1] = 0;
        }
      } else {
        ++psum[freq[a[i]]];
        sets[--freq[a[i]]].insert(a[i]);
      }
    }
    for (int i = 0; i < q; ++i) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
}
