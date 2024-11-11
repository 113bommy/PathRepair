#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 10;
vector<int> a;
vector<int> b;
vector<int> t[N * 4];
map<int, int> id;
void init(int u, int b, int e) {
  if (b == e) {
    t[u].push_back(a[b]);
    return;
  }
  int l = u << 1, r = l + 1, m = (b + e) >> 1;
  init(l, b, m);
  init(r, m + 1, e);
  merge(t[l].begin(), t[l].end(), t[r].begin(), t[r].end(),
        back_inserter(t[u]));
}
int q(int u, int b, int e, int i, int j, int k) {
  if (j < b or e < i) return 0;
  if (i <= b and e <= j) {
    return t[u].size() -
           (upper_bound(t[u].begin(), t[u].end(), k) - t[u].begin());
  }
  int l = u << 1, r = l + 1, m = (b + e) >> 1;
  return q(l, b, m, i, j, k) + q(r, m + 1, e, i, j, k);
}
int bs(int l, int r) {
  int x = lower_bound(b.begin(), b.end(), l) - b.begin();
  int y = lower_bound(b.begin(), b.end(), r) - b.begin();
  int len = abs(x - y) + 1;
  return len;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (!id[a]) id[a] = a;
    if (!id[b]) id[b] = b;
    swap(id[a], id[b]);
  }
  for (auto p : id) {
    a.push_back(p.second);
    b.push_back(p.first);
  }
  int m = (int)a.size();
  init(1, 0, m - 1);
  sort(b.begin(), b.end());
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    cnt += q(1, 0, m - 1, 0, i, a[i]);
    cnt += (abs(id[a[i]] - a[i]) + 1) - bs(id[a[i]], a[i]);
  }
  cout << cnt << '\n';
}
