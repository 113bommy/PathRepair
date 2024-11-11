#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;
const long long int INF = 2e9 + 1;
unordered_set<int> isy[100100];
vector<int> yx[100100];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < (n); i++) {
    int x, y;
    cin >> x >> y;
    yx[y].push_back(x);
    isy[x].insert(y);
  }
  for (int i = 0; i < (100100); i++) {
    sort(yx[i].begin(), yx[i].end());
  }
  long long int ans = 0;
  for (int x = 0; x < (100100); x++) {
    for (auto it : isy[x]) {
      int y = it;
      if ((int)(isy[x]).size() < (int)(yx[y]).size()) {
        for (auto it2 : isy[x]) {
          int d = it2 - y;
          if (d > 0) ans += isy[x + d].count(y) && isy[x + d].count(y + d);
        }
      } else {
        for (int j = 0; j < ((int)(yx[y]).size()); j++) {
          int d = yx[y][j] - y;
          if (d > 0) {
            ans += isy[x].count(y + d) && isy[x + d].count(y + d);
          }
        }
      }
    }
  }
  cout << ans;
}
