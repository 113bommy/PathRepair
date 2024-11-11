#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 18);
int t1[maxn];
int t2[maxn];
void add(int *t, int p, int val) {
  for (; p < maxn; p += (p & -p)) t1[p] += val;
}
int fnd(int k, int li) {
  int now = 0;
  for (int i = 17; i >= 0; --i) {
    if (t1[now + (1 << i)] + min(li, t2[now + (1 << i)]) < k) {
      k -= (t1[now + (1 << i)] + min(li, t2[now + (1 << i)]));
      li -= min(li, t2[now + (1 << i)]);
      now += (1 << i);
    }
  }
  return now + 1;
}
vector<int> pos[maxn];
int a[maxn], b[maxn];
int ans[maxn];
struct Node {
  int k, p;
  int no;
} node[maxn];
void addall(int *t, vector<int> &p, int val) {
  for (int i = 0; i < p.size(); ++i) add(t, p[i], val);
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int m;
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> node[i].k >> node[i].p;
    node[i].no = i;
  }
  sort(node + 1, node + 1 + m,
       [](const Node &a, const Node &b) { return a.k < b.k; });
  for (int i = 1; i <= n; ++i) b[i] = a[i];
  sort(b + 1, b + 1 + n);
  int d = unique(b + 1, b + 1 + n) - (b + 1);
  for (int i = 1; i <= n; ++i) a[i] = lower_bound(b + 1, b + 1 + d, a[i]) - b;
  for (int i = 1; i <= n; ++i) pos[a[i]].push_back(i);
  int nowsz = 0;
  addall(t2, pos[d], 1);
  for (int q = 1; q <= m; ++q) {
    while (nowsz + pos[d].size() < node[q].k) {
      addall(t2, pos[d], -1);
      addall(t1, pos[d], 1);
      nowsz += pos[d].size();
      --d;
      addall(t2, pos[d], 1);
    }
    ans[node[q].no] = fnd(node[q].p, node[q].k - nowsz);
  }
  for (int q = 1; q <= m; ++q) {
    cout << b[a[ans[q]]] << endl;
  }
  return 0;
}
