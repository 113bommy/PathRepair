#include <bits/stdc++.h>
using namespace std;
vector<int> X[100005], Y[100005];
int point[200005][2];
unordered_set<long long> all;
long long Make_pair(long long a, long long b) {
  if (a < 0 || b < 0) return -1;
  return a * 100005ll * b;
}
int main() {
  int ans = 0, i, n;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &point[i][0]);
    scanf("%d", &point[i][1]);
    X[point[i][0]].push_back(point[i][1]);
    Y[point[i][1]].push_back(point[i][0]);
    all.insert(Make_pair(point[i][0], point[i][1]));
  }
  for (i = 0; i < 100005; i++) {
    sort(X[i].begin(), X[i].end());
    sort(Y[i].begin(), Y[i].end());
  }
  for (i = 0; i < n; i++) {
    int x = point[i][0], y = point[i][1];
    if (X[x].size() < Y[y].size()) {
      for (int j = 0; j < X[x].size() && X[x][j] < y; j++) {
        if (all.find(Make_pair(x - y + X[x][j], y)) != all.end() &&
            all.find(Make_pair(x - y + X[x][j], X[x][j])) != all.end())
          ans++;
      }
    } else {
      for (int j = 0; j < Y[y].size() && Y[y][j] < x; j++) {
        if (all.find(Make_pair(x, y - x + Y[y][j])) != all.end() &&
            all.find(Make_pair(Y[y][j], y - x + Y[y][j])) != all.end())
          ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
