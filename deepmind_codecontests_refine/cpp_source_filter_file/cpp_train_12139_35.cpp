#include <bits/stdc++.h>
using namespace std;
int n, k, a[100005], b[100005], q;
vector<int> ke[100005], t[100005 * 4];
void setup() {
  cin >> n >> k;
  for (long long i = (1); i <= (n); i++) {
    cin >> a[i];
    ke[a[i]].push_back(i);
  }
}
void add(int x) {
  int y = x * 2, z = x * 2 + 1;
  int i = 0, j = 0, cnt = 0;
  t[x].resize(t[y].size() + t[z].size());
  while (i < t[y].size() || j < t[z].size()) {
    if (i == t[y].size())
      t[x][cnt++] = t[z][j++];
    else if (j == t[z].size())
      t[x][cnt++] = t[y][i++];
    else if (t[y][i] < t[z][j])
      t[x][cnt++] = t[y][i++];
    else
      t[x][cnt++] = t[z][j++];
  }
}
void build(int node, int l, int r) {
  if (l == r) {
    t[node].push_back(b[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(node * 2, l, mid);
  build(node * 2 + 1, mid + 1, r);
  add(node);
}
int get(int node, int l, int r, int u, int v) {
  if (l > v || u > r) return 0;
  if (u <= l && r <= v) {
    int pos = lower_bound(t[node].begin(), t[node].end(), l) - t[node].begin();
    return pos;
  }
  int mid = (l + r) >> 1;
  int m1 = get(node * 2, l, mid, u, v);
  int m2 = get(node * 2 + 1, mid + 1, r, u, v);
  return m1 + m2;
}
void work() {
  for (long long i = (1); i <= (n); i++) {
    int pos =
        lower_bound(ke[a[i]].begin(), ke[a[i]].end(), i) - ke[a[i]].begin();
    if (pos < k)
      b[i] = 0;
    else
      b[i] = ke[a[i]][pos - k];
  }
  build(1, 1, n);
  cin >> q;
  int last = 0;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l = ((l + last) % n) + 1;
    r = ((r + last) % n) + 1;
    if (l > r) swap(l, r);
    cout << (last = get(1, 1, n, l, r)) << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  setup();
  work();
  return 0;
}
