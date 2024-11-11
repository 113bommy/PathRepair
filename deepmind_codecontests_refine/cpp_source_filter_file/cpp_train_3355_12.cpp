#include <bits/stdc++.h>
using namespace std;
int n, m, i;
int v[300005], aib[300005], viz[300005], lst[300005];
pair<int, int> p[300005];
void update(int x, int val) {
  for (; x <= n; x += (x & -x)) {
    aib[x] += val;
  }
}
int query(int x) {
  int sum = 0;
  for (; x >= 1; x -= (x & -x)) {
    sum += aib[x];
  }
  return sum;
}
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    p[i] = make_pair(i, i);
  }
  for (i = m; i >= 1; i--) {
    cin >> v[i];
    p[v[i]].first = 1;
    viz[v[i]] = 1;
  }
  for (i = n; i >= 1; i--) {
    if (viz[i] == 0) {
      p[i].second = i + viz[i + 1];
    }
    viz[i] += viz[i + 1];
  }
  memset(viz, 0, sizeof(viz));
  for (i = m; i >= 1; i--) {
    if (viz[v[i]] == 0) {
      viz[v[i]] = 1;
      p[v[i]].second = v[i] + query(n - v[i] + 1);
      update(n - v[i] + 1, 1);
    }
  }
  memset(aib, 0, sizeof(aib));
  for (i = 1; i <= m; i++) {
    p[v[i]].second = max(p[v[i]].second, 1 + query(n) - query(lst[v[i]]));
    if (lst[v[i]] != 0) {
      update(lst[v[i]], -1);
    }
    lst[v[i]] = i;
    update(i, 1);
  }
  for (i = 1; i <= n; i++) {
    cout << p[i].first << " " << p[i].second << "\n";
  }
}
