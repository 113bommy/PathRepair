#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
int killed[100000], val[100000];
int main() {
  ios::sync_with_stdio(0);
  int n, ans = 0;
  vector<int> S(1, 0);
  cin >> n;
  killed[0] = -1;
  for (int i = 0; i < n; i++) cin >> val[i];
  for (int i = 1; i < n; i++) {
    while (S.size() > 0 && val[S.back()] < val[i]) {
      killed[i] = max(killed[i], killed[S.back()] + 1);
      S.pop_back();
    }
    if (S.empty()) killed[i] = -1;
    ans = max(ans, killed[i] + 1);
    S.push_back(i);
  }
  cout << ans << endl;
}
