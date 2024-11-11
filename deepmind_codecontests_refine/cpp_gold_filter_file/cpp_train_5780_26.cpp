#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 111;
int n, m;
int id[MAX];
pair<int, int> a[MAX], ans[MAX];
vector<int> ed;
bool cmp(int i, int j) {
  return a[i].first < a[j].first ||
         (a[i].first == a[j].first && a[i].second > a[j].second);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a[i].first >> a[i].second;
    id[i] = i;
  }
  sort(id, id + m, cmp);
  int edges = 0, ver = 1;
  int last = 0;
  for (int i = 0; i < m; ++i) {
    if (a[id[i]].second == 0 && ver * (ver - 1) / 2 - edges == 0) {
      cout << -1;
      return 0;
    }
    if (a[id[i]].second == 1)
      ans[id[i]] = make_pair(last, last + 1), ++last, ++ver;
    else
      ed.push_back(id[i]);
    ++edges;
  }
  reverse(ed.begin(), ed.end());
  for (int i = 0; i < n; ++i) {
    if (ed.size() == 0) break;
    for (int j = 0; j < i - 1; ++j) {
      if (ed.size() > 0) {
        ans[ed.back()] = make_pair(i, j);
        ed.pop_back();
      }
    }
  }
  for (int i = 0; i < m; ++i)
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
  return 0;
}
