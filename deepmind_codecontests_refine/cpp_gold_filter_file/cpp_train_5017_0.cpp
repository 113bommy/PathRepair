#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a, b;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  a.resize(n);
  for (auto &i : a) cin >> i;
  b.resize(n);
  for (auto &i : b) cin >> i;
  vector<int> vis(n + 1);
  int cura = 0, curb = 0;
  int ans = 0;
  while (curb < n) {
    if (vis[a[cura]]) {
      cura++;
      continue;
    }
    if (b[curb] == a[cura]) {
      cura++, curb++;
    } else {
      vis[b[curb]] = 1;
      ans++;
      curb++;
    }
  }
  cout << ans << endl;
}
