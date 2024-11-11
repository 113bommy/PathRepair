#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 3e5 + 10;
const int oo = 1e9 + 10;
pair<int, int> a[MAX_N];
pair<pair<int, int>, int> b[MAX_N];
vector<pair<int, int> > v;
vector<int> values, tmp;
int node[10 * MAX_N];
void build(int x, int l, int h) {
  if (l == h) {
    node[x] = 0;
    return;
  }
  int mid = (l + h) / 2;
  build(2 * x, l, mid);
  build(2 * x + 1, mid + 1, h);
  node[x] = node[2 * x] + node[2 * x + 1];
}
void update(int x, int l, int h, int pos, int val) {
  if (pos < l || h < pos) {
    return;
  }
  if (l == pos && pos == h) {
    node[x] += val;
    return;
  }
  int mid = (l + h) / 2;
  update(2 * x, l, mid, pos, val);
  update(2 * x + 1, mid + 1, h, pos, val);
  node[x] = node[2 * x] + node[2 * x + 1];
}
int get(int x, int l, int h, int i, int j) {
  if (j < l || h < i) {
    return 0;
  }
  if (i <= l && h <= j) {
    return node[x];
  }
  int mid = (l + h) / 2;
  return get(2 * x, l, mid, i, j) + get(2 * x + 1, mid + 1, h, i, j);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  values.push_back(-oo);
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    values.push_back(x);
    values.push_back(y);
    a[i] = make_pair(x, y);
  }
  sort(values.begin(), values.end());
  values.resize(unique(values.begin(), values.end()) - values.begin());
  int m = values.size() - 1;
  for (int i = 1; i <= n; i++) {
    int l =
        lower_bound(values.begin(), values.end(), a[i].first) - values.begin();
    int h =
        lower_bound(values.begin(), values.end(), a[i].second) - values.begin();
    b[i] = make_pair(make_pair(l, h), i);
  }
  sort(b + 1, b + n + 1);
  build(1, 1, m);
  long long ans = 0;
  pair<int, int> res = make_pair(0, 0);
  int curPos = 0;
  for (int i = 1; i <= m; i++) {
    while (curPos + 1 <= n && b[curPos + 1].first.first <= i) {
      curPos++;
      update(1, 1, m, b[curPos].first.second, 1);
    }
    int low = i;
    int high = m;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (get(1, 1, m, mid, m) >= k) {
        if (values[mid] - values[i] + 1 >= ans) {
          ans = values[mid] - values[i] + 1;
          res = make_pair(i, mid);
        }
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }
  cout << ans << "\n";
  if (ans == 0) {
    for (int i = 1; i <= k; i++) {
      cout << i << " ";
    }
    cout << "\n";
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    if (b[i].first.first > res.first) break;
    v.push_back(make_pair(b[i].first.second, b[i].second));
  }
  sort(v.begin(), v.end());
  int s = v.size() - 1;
  for (int i = 0; i < k; i++) {
    tmp.push_back(v[s - i].second);
  }
  sort(tmp.begin(), tmp.end());
  for (int i = 0; i < tmp.size(); i++) {
    cout << tmp[i] << " ";
  }
  cout << "\n";
}
