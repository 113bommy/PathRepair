#include <bits/stdc++.h>
using namespace std;
template <class T>
void check_max(T& a, T b) {
  if (a < b) a = b;
}
template <class T>
void check_min(T& a, T b) {
  if (a > b) a = b;
}
const int MAXN = 1E5 + 10;
int n;
int p[MAXN];
vector<int> e[MAXN];
long long v[MAXN];
int root;
int depth[MAXN];
long long in_v[MAXN];
int in_id[MAXN], in_c;
void dfs_in(int i) {
  if (e[i].size() > 0) {
    dfs_in(e[i][0]);
    in_v[in_c] = v[i];
    in_id[in_c] = i;
    in_c++;
    dfs_in(e[i][1]);
  }
}
long long sub_max[MAXN], sub_min[MAXN];
void dfs_d(int i, int d) {
  depth[i] = d;
  if (e[i].size() > 0) {
    dfs_d(e[i][0], d + 1);
    dfs_d(e[i][1], d + 1);
    sub_min[i] = sub_min[e[i][0]];
    sub_max[i] = sub_min[e[i][1]];
  } else {
    sub_max[i] = sub_min[i] = v[i];
  }
}
long long sum[MAXN];
void dfs_pre(int i) {
  sum[i] = (p[i] == -1) ? 0 : sum[p[i]];
  if (p[i] != -1) {
    if (i == e[p[i]][0])
      sum[i] += sub_min[e[p[i]][1]];
    else
      sum[i] += sub_max[e[p[i]][0]];
  }
  if (e[i].size() > 0) {
    dfs_pre(e[i][0]);
    dfs_pre(e[i][1]);
  }
}
int main() {
  cin >> n;
  for (int _t = n, i = 0; i < _t; i++) e[i].clear();
  for (int _t = n, i = 0; i < _t; i++) {
    cin >> p[i] >> v[i];
    if (p[i] == -1)
      root = i;
    else {
      p[i]--;
      e[p[i]].push_back(i);
    }
  }
  for (int _t = n, i = 0; i < _t; i++)
    if (e[i].size() > 0) {
      if (v[e[i][0]] > v[e[i][1]]) swap(e[i][0], e[i][1]);
    }
  in_c = 0;
  dfs_in(root);
  dfs_d(root, 0);
  dfs_pre(root);
  int k;
  cin >> k;
  while (k-- > 0) {
    int cv;
    cin >> cv;
    int it = lower_bound(in_v, in_v + in_c, cv) - in_v;
    int i;
    if (it == 0)
      i = e[in_id[0]][0];
    else if (it == in_c)
      i = e[in_id[in_c - 1]][1];
    else {
      int l = in_id[it - 1], r = in_id[it];
      if (depth[l] > depth[r])
        i = e[l][1];
      else
        i = e[r][0];
    }
    double ans = 1.0 * sum[i] / (depth[i] + .0);
    printf("%.10lf\n", ans);
  }
  return 0;
}
