#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996);
int n, m, x;
map<int, int> have;
vector<int> ans;
void solve() {
  int i, j;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> x;
    have[x] = 1;
  }
  int now = 1;
  while (now < 1e9 && m >= now) {
    if (have[now] == 0) {
      m -= now;
      ans.push_back(now);
    }
    now++;
  }
  cout << ans.size() << endl;
  for (i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
}
int main() {
#pragma comment(linker, "/STACK:1073741824"
  solve();
  return 0;
}
