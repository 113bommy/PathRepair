#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int xx[1000005], yy[1000005];
vector<pair<pair<int, int>, pair<int, int> > > v;
int fl = 0;
int g1() {
  int i, j;
  vector<int> col;
  col.push_back(1);
  col.push_back(m);
  for (int i = 0; i < v.size(); i++) {
    col.push_back(max(1, v[i].first.second - 1));
    col.push_back(min(m, v[i].first.second + 1));
    col.push_back(v[i].first.second);
    col.push_back(max(1, v[i].second.second - 1));
    col.push_back(min(m, v[i].second.second + 1));
    col.push_back(v[i].second.second);
  }
  sort(col.begin(), col.end());
  unique(col.begin(), col.end());
  int ans = -1;
  for (i = 0; i < col.size(); i++) {
    vector<pair<int, int> > tr;
    for (j = 0; j < v.size(); j++) {
      int col1 = v[j].first.second;
      int col2 = v[j].second.second;
      int row1 = v[j].first.first;
      int row2 = v[j].second.first;
      if (col1 <= col[i] && col2 >= col[i]) tr.push_back({row1, row2});
    }
    sort(tr.begin(), tr.end());
    if (tr.size() == 0) {
      ans = col[i];
      break;
    }
    if (tr[0].first != 1) {
      ans = col[i];
      break;
    }
    int r = tr[0].second;
    for (j = 1; j < tr.size(); j++) {
      if (tr[j].first > r + 1) {
        ans = col[i];
        break;
      }
      r = max(tr[j].second, r);
    }
    if (r != n) {
      ans = col[i];
      break;
    }
  }
  return ans;
}
int g2() {
  int i, j;
  vector<int> row;
  row.push_back(1);
  row.push_back(n);
  for (int i = 0; i < v.size(); i++) {
    row.push_back(max(1, v[i].first.first - 1));
    row.push_back(min(n, v[i].first.first + 1));
    row.push_back(v[i].first.first);
    row.push_back(max(1, v[i].second.first - 1));
    row.push_back(min(n, v[i].second.first + 1));
    row.push_back(v[i].second.first);
  }
  sort(row.begin(), row.end());
  unique(row.begin(), row.end());
  int ans = -1;
  for (i = 0; i < row.size(); i++) {
    vector<pair<int, int> > tr;
    for (j = 0; j < v.size(); j++) {
      int row1 = v[j].first.first;
      int row2 = v[j].second.first;
      int col1 = v[j].first.second;
      int col2 = v[j].second.second;
      if (row1 <= row[i] && row2 >= row[i]) tr.push_back({col1, col2});
    }
    sort(tr.begin(), tr.end());
    if (tr.size() == 0) {
      ans = row[i];
      break;
    }
    if (tr[0].first != 1) {
      ans = row[i];
      break;
    }
    int r = tr[0].second;
    for (j = 1; j < tr.size(); j++) {
      if (tr[j].first > r + 1) {
        ans = row[i];
        break;
      }
      r = max(tr[j].second, r);
    }
    if (r != m) {
      ans = row[i];
      break;
    }
  }
  return ans;
}
bool f(int t) {
  v.clear();
  for (int i = 0; i < k; i++) {
    v.push_back({{max(1, xx[i] - t), max(1, yy[i] - t)},
                 {min(n, xx[i] + t), min(m, yy[i] + t)}});
  }
  int x = g2();
  int y = g1();
  v.push_back({{max(1, x), max(1, y)}, {min(n, x + 2 * t), min(m, y + 2 * t)}});
  fl = 1;
  return (g2() == -1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int i;
  cin >> n >> m >> k;
  for (i = 0; i < k; i++) cin >> xx[i] >> yy[i];
  if (k + 1 == n * m) {
    cout << 0 << endl;
    return 0;
  }
  int l = 1, r = 1000000003LL;
  while (l != r) {
    int mid = (l + r) / 2;
    if (f(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l;
  return 0;
}
