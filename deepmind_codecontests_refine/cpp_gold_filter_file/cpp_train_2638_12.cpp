#include <bits/stdc++.h>
using namespace std;
using namespace std;
int h, m, n;
vector<int> tree[200010];
pair<int, int> A[200010];
int vis[200010] = {0};
map<int, pair<int, int> > M;
void upd(int i, int idx, int val) {
  while (idx < tree[i].size()) {
    tree[i][idx] += val;
    idx += idx & -idx;
  }
}
int read(int i, int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += tree[i][idx];
    idx -= idx & -idx;
  }
  return sum;
}
int solve(int i, int pos, int id) {
  int val = read(i, tree[i].size() - 1) - read(i, pos - 1);
  if (val < (tree[i].size() - pos)) {
    int l = pos, r = tree[i].size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      val = read(i, mid) - read(i, pos - 1);
      if (val < (mid - pos + 1))
        r = mid;
      else
        l = mid + 1;
    }
    M[id] = pair<int, int>(i, l);
    upd(i, l, 1);
    return (l - pos);
  } else {
    int l = 1, r = pos - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      val = read(i, mid);
      if (val < mid)
        r = mid;
      else
        l = mid + 1;
    }
    M[id] = pair<int, int>(i, l);
    upd(i, l, 1);
    return (tree[i].size() - pos + l - 1);
  }
}
int main() {
  cin >> h >> m >> n;
  int idx = 0;
  for (int i = 0; i < h; i++) {
    if (vis[i] != 0) continue;
    int cur = i;
    tree[idx].push_back(0);
    int val = 1;
    do {
      vis[cur] = 1;
      A[cur] = pair<int, int>(idx, val);
      tree[idx].push_back(0);
      val++;
      cur = (cur + m) % h;
    } while (cur != i);
    idx++;
  }
  long long int ans = 0;
  while (n--) {
    char c;
    int id, hash;
    cin >> c;
    if (c == '+') {
      cin >> id >> hash;
      ans += (long long int)solve(A[hash].first, A[hash].second, id);
    } else {
      cin >> id;
      pair<int, int> p = M[id];
      upd(p.first, p.second, -1);
      M.erase(id);
    }
  }
  cout << ans << endl;
  return 0;
}
