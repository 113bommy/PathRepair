#include <bits/stdc++.h>
using namespace std;
const int MAX = 4000;
pair<int, int> coor[110];
bool ok[110];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> coor[i].first >> coor[i].second;
  for (int i = 1; i < n; i++) {
    for (int j = coor[i].first; j < coor[i].second; j++) ok[j] = true;
  }
  int ans = 0;
  for (int i = coor[0].first; i < coor[0].second; i++) {
    if (!ok[i]) ans++;
  }
  cout << ans;
}
