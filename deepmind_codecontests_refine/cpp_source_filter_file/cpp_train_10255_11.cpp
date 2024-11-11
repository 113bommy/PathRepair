#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;
int main() {
  int n;
  cin >> n;
  int a[n], b[n], pb[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b[i]--;
    pb[b[i]] = i;
  }
  int res = 0;
  vector<pair<int, int>> p;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) continue;
    bool f = false;
    for (int j = i; j <= pb[a[i]]; j++) {
      if (pb[a[j]] <= i) {
        swap(a[i], a[j]);
        res += j - i;
        f = true;
        p.push_back({a[i] + 1, a[j] + 1});
      }
    }
    if (f) i = -1;
  }
  cout << res << '\n' << p.size() << '\n';
  for (auto x : p) cout << x.first << " " << x.second << '\n';
  return 0;
}
