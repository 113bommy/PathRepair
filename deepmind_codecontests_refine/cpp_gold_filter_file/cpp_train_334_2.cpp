#include <bits/stdc++.h>
using namespace std;
int n;
int it[800005];
int a[200005], b[200005];
int at[200005];
int pos[200005];
vector<pair<pair<int, int>, int> > ax;
void update(int id, int l, int r, int pos, int val) {
  if (l == r) {
    it[id] = val;
    return;
  }
  int mid = (l + r) / 2;
  if (pos > mid) {
    update(id * 2 + 1, mid + 1, r, pos, val);
  } else {
    update(id * 2, l, mid, pos, val);
  }
  it[id] = min(it[id * 2], it[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v) {
  if (l > v || r < u) {
    return 1000000000;
  }
  if (u <= l && v >= r) {
    return it[id];
  }
  int mid = (l + r) / 2;
  return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
void build_tree(int id, int l, int r) {
  if (l == r) {
    it[id] = l;
    return;
  }
  int mid = (l + r) / 2;
  build_tree(id * 2, l, mid);
  build_tree(id * 2 + 1, mid + 1, r);
  it[id] = min(it[id * 2], it[id * 2 + 1]);
}
signed main() {
  cin >> n;
  build_tree(1, 1, n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    ax.push_back({{b[i], a[i]}, i});
  }
  sort(ax.begin(), ax.end());
  for (auto i : ax) {
    int ok = get(1, 1, n, i.first.second, i.first.first);
    at[ok] = i.second;
    pos[i.second] = ok;
    update(1, 1, n, ok, 100000000);
  }
  memset(it, 0, sizeof(it));
  for (int i = 1; i <= n; i++) {
    update(1, 1, n, i, -b[at[i]]);
  }
  for (int i = 1; i <= n; i++) {
    if (a[at[i]] == i) continue;
    int ok = get(1, 1, n, a[at[i]], i - 1);
    if (abs(ok) >= i) {
      for (int j = a[at[i]]; j < i; j++) {
        if (b[at[j]] >= i) {
          cout << "NO\n";
          for (int k = 1; k <= n; k++) {
            cout << pos[k] << " ";
          }
          cout << endl;
          swap(pos[at[i]], pos[at[j]]);
          for (int k = 1; k <= n; k++) {
            cout << pos[k] << " ";
          }
          return 0;
        }
      }
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << pos[i] << " ";
  }
}
