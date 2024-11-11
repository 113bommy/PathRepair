#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[200010], b[200010];
int si[200010];
int root[200010];
vector<int> v[200010];
vector<int> v2[200010];
int fnd(int x) {
  if (root[x] == x) return x;
  return root[x] = fnd(root[x]);
}
void add(int x, int y) {
  x = fnd(x);
  y = fnd(y);
  if (x == y) return;
  if (si[x] > si[y]) swap(x, y);
  root[x] = y;
  si[y] += si[x];
}
int main() {
  for (int i = 0; i < 200010; i++) root[i] = i;
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
    si[a[i]] = b[a[i]];
    v[a[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    int x = a[i];
    int j = v[x].back();
    for (; i <= j; i++) {
      add(x, a[i]);
      j = max(j, v[a[i]].back());
    }
  }
  int ans = 0;
  for (int i = 0; i < 200010; i++) {
    if (b[i] == 0) continue;
    int x = root[i];
    v2[x].push_back(b[i]);
  }
  for (int i = 0; i < 200010; i++) {
    int sum = 0, mx = 0;
    for (int x : v2[i]) {
      sum += x;
      mx = max(x, mx);
    }
    ans += sum - mx;
  }
  cout << ans;
  return 0;
}
