#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
int a[N], b[N];
pair<int, int> r[N], nr[N];
int id;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) cin >> r[i].second >> r[i].first, r[i].second--;
  for (int i = 1; i <= m; ++i) {
    while (id > 0 && r[i].first >= nr[id].first) id--;
    if (id == 0 || nr[id].second != r[i].second) nr[++id] = r[i];
  }
  for (int i = 1; i <= nr[1].first; ++i) b[i] = a[i];
  sort(b + 1, b + nr[1].first + 1);
  nr[id + 1] = {0, 0};
  int u = 1, v = nr[1].first;
  for (int i = 1; i <= id; ++i)
    for (int j = nr[i].first; j > nr[i + 1].first; --j)
      if (nr[i].second == 0)
        a[j] = b[v--];
      else
        a[j] = b[u++];
  for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
}
