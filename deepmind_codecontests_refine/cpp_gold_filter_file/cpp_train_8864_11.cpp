#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> A[200005];
pair<int, int> B[200005];
int C[500005];
int D[18][200005];
int ans, x, y, dir;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> A[i].first >> A[i].second;
  }
  for (int i = 0; i < m; i++) {
    cin >> B[i].first >> B[i].second;
  }
  sort(A, A + n);
  pair<int, int> xx(0, -1);
  for (int i = 0; i <= 500005; i++) {
    while (ans < n && A[ans].first == i) {
      xx = max(xx, make_pair(A[ans].second, ans));
      ans++;
    }
    C[i] = xx.first <= i ? -1 : xx.second;
  }
  for (int i = 0; i < n; i++) {
    D[0][i] = C[A[i].second];
  }
  for (int i = 1; i < 18; i++) {
    for (int j = 0; j < n; j++) {
      if (D[i - 1][j] == -1) {
        D[i][j] = -1;
      } else {
        D[i][j] = D[i - 1][D[i - 1][j]];
      }
    }
  }
  for (int i = 0; i < m; i++) {
    x = C[B[i].first];
    dir = 1;
    if (x == -1) {
      cout << -1 << endl;
      continue;
    }
    for (int j = 17; j >= 0; j--) {
      y = D[j][x];
      if (y == -1) {
        continue;
      }
      if (A[y].second < B[i].second) {
        dir = dir + (1 << j);
        x = y;
      }
    }
    if (A[x].second >= B[i].second) {
      cout << dir << endl;
    } else if (D[0][x] == -1) {
      cout << -1 << endl;
    } else {
      cout << dir + 1 << endl;
    }
  }
}
