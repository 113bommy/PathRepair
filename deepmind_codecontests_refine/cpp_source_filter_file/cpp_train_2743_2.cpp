#include <bits/stdc++.h>
using namespace std;
bool visit[204];
vector<int> dependency[204];
int col[203];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> col[i];
  }
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    for (int j = 1; j <= k; j++) {
      int m;
      cin >> m;
      dependency[i].push_back(m);
    }
  }
  int ans = INT_MAX;
  for (int l = 1; l <= 3; l++) {
    int hours = 0, cur = l, vis = 0;
    for (int i = 1; i <= n; i++) {
      visit[i] = false;
    }
    while (vis != n) {
      bool cvis = false;
      for (int i = 1; i <= n; i++) {
        if (!visit[i] && col[i] == cur) {
          bool cr = true;
          for (int j = 0; j < dependency[i].size(); j++) {
            if (!visit[dependency[i][j]]) {
              cr = false;
              break;
            }
          }
          if (cr) {
            visit[i] = true;
            vis++;
            cvis = true;
            hours++;
            break;
          }
        }
      }
      if (!cvis) {
        cur = 1 + (cur + 1) % 3;
        hours++;
      }
    }
    ans = min(ans, hours);
  }
  cout << ans << endl;
  return 0;
}
