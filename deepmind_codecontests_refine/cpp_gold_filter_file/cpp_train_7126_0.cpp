#include <bits/stdc++.h>
using namespace std;
map<int, int> parent;
map<int, int> visit;
map<int, int> grp;
int find(int x) {
  if (parent[x] == x)
    return x;
  else {
    parent[x] = find(parent[x]);
    return parent[x];
  }
}
int uni(int x, int y) { parent[find(x)] = find(y); }
int main() {
  int n, A, B;
  cin >> n >> A >> B;
  int a[n + 2], i;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    parent[i] = i;
    visit[a[i]] = i;
    grp[i] = 0;
  }
  for (i = 1; i <= n; i++) {
    if (visit[A - a[i]]) {
      uni(i, visit[A - a[i]]);
      grp[i] += 1;
    }
    if (visit[B - a[i]]) {
      uni(i, visit[B - a[i]]);
      grp[i] += 2;
    }
  }
  int f = 0;
  map<int, int> final;
  for (i = 1; i <= n; i++) {
    final[i] = 3;
  }
  for (i = 1; i <= n; i++) final[find(i)] &= grp[i];
  for (i = 1; i <= n; i++) {
    if (final[(find(i))] == 0) {
      cout << "NO\n";
      f = 1;
      break;
    }
  }
  if (f == 0) {
    cout << "YES\n";
    for (i = 1; i <= n; i++) {
      if (final[find(i)] == 1)
        cout << "0 ";
      else
        cout << "1 ";
    }
  }
  return 0;
}
