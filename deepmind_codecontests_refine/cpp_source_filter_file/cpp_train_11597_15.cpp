#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int s[maxn], a[maxn], b[maxn];
int n;
int main() {
  cin >> n;
  vector<pair<int, int>> e(n);
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    e[i - 1] = {s[i], i};
  }
  sort(begin(e), end(e));
  int idx = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < (n + 2) / 3; ++j) {
      if (idx + j >= n) break;
      auto v = e[idx + j];
      if (i == 0) {
        a[v.second] = idx + j;
        b[v.second] = v.first - idx - j;
      } else if (i == 1) {
        a[v.second] = v.first - idx - j;
        b[v.second] = idx + j;
      } else {
        a[v.second] = v.first - (n + 2) / 3 + j;
        b[v.second] = (n + 2) / 3 - j;
      }
    }
    idx += (n + 2) / 3;
  }
  puts("YES");
  for (int i = 1; i <= n; ++i) cout << a[i] << " ";
  cout << endl;
  for (int i = 1; i <= n; ++i) cout << b[i] << " ";
  cout << endl;
  return 0;
}
