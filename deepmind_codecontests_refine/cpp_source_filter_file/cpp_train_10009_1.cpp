#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
pair<int, int> a[N][N], b[N][N];
int smallerx[N][N], smallery[N][N], biggerx[N][N], biggery[N][N];
int n, m;
int calc(int i, int j) {
  return 1 + max(biggerx[i][j], biggery[i][j]) +
         max(smallerx[i][j], smallery[i][j]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j].first);
      a[i][j].second = j;
      b[j][i].first = a[i][j].first;
      b[j][i].second = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    int cnt = -1, curr = -1;
    sort(a[i] + 1, a[i] + m + 1);
    for (int k = 1; k <= m; k++) {
      int j = a[i][k].second;
      if (a[i][k].first > curr) {
        cnt++;
        curr = a[i][k].first;
      }
      smallerx[i][j] = cnt;
    }
  }
  for (int i = 1; i <= n; i++) {
    int curr = 1e9 + 5, cnt = -1;
    sort(a[i] + 1, a[i] + m + 1, greater<pair<int, int> >());
    for (int k = 1; k <= m; k++) {
      int j = a[i][k].second;
      if (a[i][k].first < curr) {
        cnt++;
        curr = a[i][k].first;
      }
      biggerx[i][j] = cnt;
    }
  }
  for (int j = 1; j <= m; j++) {
    int cnt = -1, curr = -1;
    sort(b[j] + 1, b[j] + n + 1);
    for (int k = 1; k <= n; k++) {
      int i = b[j][k].second;
      if (b[j][k].first > curr) {
        cnt++;
        curr = b[j][k].first;
      }
      smallery[i][j] = cnt;
    }
  }
  for (int j = 1; j <= m; j++) {
    int curr = 1e9 + 5, cnt = -1;
    sort(b[j] + 1, b[j] + n + 1, greater<pair<int, int> >());
    for (int k = 1; k <= n; k++) {
      int i = b[j][k].second;
      if (b[j][k].first < curr) {
        cnt++;
        curr = b[i][k].first;
      }
      biggery[i][j] = cnt;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d ", calc(i, j));
    }
    printf("\n");
  }
  return 0;
}
