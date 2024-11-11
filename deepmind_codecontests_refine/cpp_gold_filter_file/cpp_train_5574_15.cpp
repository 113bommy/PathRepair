#include <bits/stdc++.h>
using namespace std;
map<int, int> cnt;
map<int, int> used;
int n, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  int a, b, l, r;
  r = 1e9;
  l = -1;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    r = min(r, max(a, b));
    l = max(l, min(a, b));
  }
  if (r == 1e9) r = n;
  if (l == -1) l = 1;
  cout << max(0, r - l);
  return 0;
}
