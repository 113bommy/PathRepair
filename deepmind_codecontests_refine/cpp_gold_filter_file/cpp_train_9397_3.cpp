#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > seulgi;
void dfs(int l, int r) {
  if (l == r) return;
  int mid = (l + r) / 2;
  dfs(l, mid);
  dfs(mid + 1, r);
  int i = l, j = mid + 1;
  while (i <= mid && j <= r) {
    seulgi.push_back({i, j});
    i++;
    j++;
  }
}
int main() {
  int n, i, j, k, x, y, ans, temp, curr, m;
  int tc;
  cin >> n;
  int now = 1;
  while (now <= n) now *= 2;
  now /= 2;
  dfs(1, now);
  dfs(n - now + 1, n);
  cout << seulgi.size() << endl;
  for (auto x : seulgi) printf("%d %d\n", x.first, x.second);
  return 0;
}
