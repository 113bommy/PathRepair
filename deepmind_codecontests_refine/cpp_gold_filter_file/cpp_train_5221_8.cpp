#include <bits/stdc++.h>
using namespace std;
const int maxn = 1505;
struct node {
  int l, r;
  node(int l, int r) : l(l), r(r) {}
  friend bool operator<(node a, node b) {
    return a.r == b.r ? a.l < b.l : a.r < b.r;
  }
};
long long sum[maxn];
map<long long, int> vis;
vector<int> V;
vector<node> Q[2250005];
vector<node> ans[2250005];
int cnt = 0;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    sum[i] = sum[i - 1] + t;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      long long t = sum[j] - sum[i - 1];
      if (!vis[t]) vis[t] = ++cnt;
      Q[vis[t]].push_back(node(i, j));
    }
  }
  int maxx = 0, p;
  for (int i = 1; i <= cnt; i++) {
    sort(Q[i].begin(), Q[i].end());
    int last = 0;
    for (auto t : Q[i]) {
      if (t.l > last) {
        last = t.r;
        ans[i].push_back(t);
      }
    }
    if (ans[i].size() > maxx) {
      maxx = ans[i].size();
      p = i;
    }
  }
  cout << ans[p].size() << endl;
  for (auto t : ans[p]) {
    cout << t.l << " " << t.r << endl;
  }
  return 0;
}
