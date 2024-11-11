#include <bits/stdc++.h>
using namespace std;
const int N = 300003;
bool dp[401][401][2][2], vis[401][401][2][2];
int n, d;
vector<pair<int, int> > vec;
bool solve(int x, int y, bool a, bool b) {
  int dist = x * x + y * y;
  if (dist > d) return true;
  if (vis[x + 200][y + 200][a][b]) return dp[x + 200][y + 200][a][b];
  vis[x + 200][y + 200][a][b] = true;
  bool win = a ? !solve(y, x, b, false) : false;
  for (int i = 0; i < n; i++) {
    int newX = x + vec[i].first;
    int newY = y + vec[i].second;
    win |= !solve(newX, newY, b, a);
  }
  return dp[x + 200][y + 200][a][b] = win;
}
int main() {
  int x, y;
  scanf("%d%d%d%d", &x, &y, &n, &d);
  d *= d;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    vec.push_back({a, b});
  }
  if (solve(x, y, true, true))
    printf("Anton");
  else
    printf("Dasha");
  return 0;
}
