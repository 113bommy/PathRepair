#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  unsigned long long t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> ans, ver(3 * n + 1, 0);
    int c = 0;
    while (m--) {
      int x, y;
      cin >> x >> y;
      if (ver[x] == 0 && ver[y] == 0) ver[x] = ver[y] = 1, ans.push_back(c);
      c++;
    }
    if (ans.size() >= n) {
      cout << "Matching" << endl;
      for (int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
      cout << endl;
    } else {
      cout << "IndSet" << endl;
      for (int i = 1, cnt = 0; i <= 3 * n && cnt < n; i++)
        if (!ver[i]) cout << i << " ", cnt++;
      cout << endl;
    }
  }
  return 0;
}
