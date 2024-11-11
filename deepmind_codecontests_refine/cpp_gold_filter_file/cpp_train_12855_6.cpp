#include <bits/stdc++.h>
using namespace std;
const int T = 1e5 * 3 + 100;
int L[T][22], R[T][22], LV[T][22], RV[T][22];
int a[T];
vector<int> num[T];
int ans[T];
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      L[i][0] = i;
      LV[i][0] = a[i];
    } else {
      L[i][0] = i - 1;
      LV[i][0] = a[i];
    }
    int v = i;
    for (int j = 1; j < 20; j++) {
      L[v][j] = L[L[v][j - 1]][j - 1];
      LV[v][j] = min(LV[v][j - 1], LV[L[v][j - 1]][j - 1]);
    }
  }
  for (int i = n; i >= 1; i--) {
    if (i == n) {
      R[i][0] = i;
      RV[i][0] = a[i];
    } else {
      R[i][0] = i + 1;
      RV[i][0] = a[i];
    }
    int v = i;
    for (int j = 1; j < 20; j++) {
      R[v][j] = R[R[v][j - 1]][j - 1];
      RV[v][j] = min(RV[v][j - 1], RV[R[v][j - 1]][j - 1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    int X = i;
    for (int j = 19; j >= 0; j--)
      if (LV[X][j] >= a[i]) X = L[X][j];
    int Y = i;
    for (int j = 19; j >= 0; j--)
      if (RV[Y][j] >= a[i]) Y = R[Y][j];
    while (a[X] < a[i]) X++;
    while (a[Y] < a[i]) Y--;
    num[Y - X + 1].push_back(a[i]);
  }
  int mx = -1;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < num[i].size(); j++) mx = max(mx, num[i][j]);
    ans[i] = mx;
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  cout << '\n';
}
