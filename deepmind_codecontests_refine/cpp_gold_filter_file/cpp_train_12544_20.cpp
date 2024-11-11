#include <bits/stdc++.h>
using namespace std;
int n = 0;
long long ans = 0;
long long limit = 2500000000;
vector<vector<vector<pair<int, int> > > > v(1001);
long long dist(long long x, long long y, long long x1, long long y1) {
  return abs(x - x1) + abs(y - y1);
}
int main() {
  cin >> n;
  int a = 0, b = 0;
  for (int i = 0; i < 1001; i++) v[i].resize(1001);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    int x = a / 1000;
    int y = a / 1000;
    v[x][y].push_back(make_pair(b, i + 1));
  }
  for (int i = 0; i < 1001; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < 1001; j++) {
        sort(v[i][j].begin(), v[i][j].end());
        for (int k = 0; k < v[i][j].size(); k++)
          printf("%d ", v[i][j][k].second);
      }
    } else {
      for (int j = 1000; j >= 0; j--) {
        sort(v[i][j].begin(), v[i][j].end());
        for (int k = v[i][j].size() - 1; k >= 0; k--)
          printf("%d ", v[i][j][k].second);
      }
    }
  }
  return 0;
}
