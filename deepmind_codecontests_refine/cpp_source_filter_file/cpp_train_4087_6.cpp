#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const int oo = 1000000007;
int n, m, topic[N];
pair<int, int> a[N];
vector<int> dsk[N];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    cin >> x >> y;
    dsk[x].push_back(y);
    dsk[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> topic[i];
    a[i].first = topic[i];
    a[i].second = i;
  }
  bool flag = true;
  for (int i = 1; i <= n; ++i) {
    set<int> s;
    for (int v : dsk[i]) {
      if (topic[i] == topic[v]) {
        flag = false;
        break;
      }
      if (topic[i] > topic[v]) s.insert(topic[v]);
    }
    if (s.size() != topic[i] - 1) flag = true;
    if (!flag) break;
  }
  if (!flag) {
    cout << -1 << endl;
    return 0;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i) cout << a[i].second << " ";
  cout << endl;
}
