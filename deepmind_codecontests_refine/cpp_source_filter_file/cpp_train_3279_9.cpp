#include <bits/stdc++.h>
using namespace std;
vector<long long int> v;
long long int a[1000000];
long long int gu[2];
long long int vis[1000000];
long long int print[1000000];
void fail() {
  cout << "NO";
  exit(0);
}
void dfs(long long int p) {
  v.push_back(p);
  vis[p] = 1;
  if (vis[a[p]] == 1)
    return;
  else
    dfs(a[p]);
}
void process() {
  long long int i, j, sum, k;
  j = 0;
  for (i = 0; i < v.size(); i++) {
    print[v[i]] = gu[j];
    j = (j + 1) % 2;
  }
}
int main() {
  long long int i, j, k, l, n, h, x, y, r, p, ans, sum, m, q;
  cin >> n;
  p = -1;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == i) p = i;
  }
  if (p != -1) {
    cout << "YES" << endl;
    for (i = 1; i <= n; i++) {
      if (i != p) {
        cout << i << " " << p << endl;
      }
    }
    exit(0);
  }
  for (i = 1; i <= n; i++) {
    x = i;
    y = a[i];
    if (a[y] == x) {
      gu[0] = x;
      gu[1] = y;
      vis[x] = 1;
      vis[y] = 1;
      break;
    }
  }
  if (i == n + 1) fail();
  for (i = 1; i <= n; i++) {
    if (vis[i] == 1) continue;
    dfs(i);
    p = v.size();
    if ((p % 2) == 1) fail;
    process();
    v.clear();
  }
  cout << "YES" << endl;
  for (i = 1; i <= n; i++) {
    if (i == x || i == y) continue;
    cout << i << " " << print[i] << endl;
  }
  cout << x << " " << y << endl;
}
