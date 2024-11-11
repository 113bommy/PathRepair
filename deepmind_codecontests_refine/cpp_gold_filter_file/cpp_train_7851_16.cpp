#include <bits/stdc++.h>
using namespace std;
long long int C[100005][105];
void combination() {
  int i, j;
  C[0][0] = 1;
  for (i = 1; i <= 100; i++) {
    C[i][0] = 1;
    for (j = 1; j < i; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      C[i][j] %= 1000000007;
    }
    C[i][i] = 1;
  }
  for (i = 101; i <= 100000; i++) {
    C[i][0] = 1;
    for (j = 1; j <= 100; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      C[i][j] %= 1000000007;
    }
  }
}
int a[100005];
long long int ans[100005];
vector<pair<int, int> > v[105];
vector<pair<int, pair<int, int> > > P;
int main() {
  combination();
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    v[z].push_back(pair<int, int>(x, y));
  }
  for (int i = 100; i >= 0; i--) {
    for (int j = 0; j < P.size(); j++) {
      ans[P[j].first] -= C[P[j].second.first][P[j].second.second];
      ans[P[j].first] %= 1000000007;
      P[j].second.first++;
      P[j].second.second++;
    }
    for (int j = 0; j < v[i].size(); j++) {
      int x, y;
      x = v[i][j].first;
      y = v[i][j].second;
      ans[x] += 1;
      ans[y + 1] -= 1;
      if (y + 1 <= n) {
        P.push_back(
            pair<int, pair<int, int> >(y + 1, pair<int, int>(y - x + 1, 1)));
      }
    }
    for (int j = 1; j <= n; j++) {
      ans[j] += ans[j - 1];
      ans[j] %= 1000000007;
    }
  }
  for (int i = 1; i <= n; i++) {
    ans[i] = ans[i] + a[i];
    ans[i] %= 1000000007;
    if (ans[i] < 0) {
      ans[i] += 1000000007;
      ans[i] %= 1000000007;
    }
    printf("%I64d ", ans[i]);
  }
  printf("\n");
  return 0;
}
