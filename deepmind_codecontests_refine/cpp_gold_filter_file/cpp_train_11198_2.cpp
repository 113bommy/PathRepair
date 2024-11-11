#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  pair<int, int> min = {0, n + 1};
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    if ((r - l) < min.second - min.first) {
      min = {l - 1, r - 1};
    }
  }
  int cnt = min.second - min.first + 1;
  cout << cnt << '\n';
  for (int i = 0; i < n; i++) {
    cout << (i + min.second + 1) % cnt << " ";
  }
  return 0;
}
