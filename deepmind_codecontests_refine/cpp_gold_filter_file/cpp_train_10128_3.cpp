#include <bits/stdc++.h>
using namespace std;
int n, m, flag;
int a[105][105];
char arr[105][105];
vector<pair<int, int>> v;
int main(void) {
  int t, T;
  scanf("%d", &T);
  for (t = 0; t < T; t++) {
    v.clear();
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%s", arr[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        a[i][j] = arr[i][j] - '0';
      }
    }
    for (int i = 0; i < n - 2; i++) {
      for (int j = 0; j < m - 1; j += 2) {
        if (a[i][j] && a[i][j + 1]) {
          v.push_back(make_pair(i + 1, j + 1));
          v.push_back(make_pair(i + 1, j + 2));
          v.push_back(make_pair(i + 2, j + 1));
          a[i + 1][j] = 1 - a[i + 1][j];
        } else if (a[i][j]) {
          v.push_back(make_pair(i + 1, j + 1));
          v.push_back(make_pair(i + 2, j + 1));
          v.push_back(make_pair(i + 2, j + 2));
          a[i + 1][j] = 1 - a[i + 1][j];
          a[i + 1][j + 1] = 1 - a[i + 1][j + 1];
        } else if (a[i][j + 1]) {
          v.push_back(make_pair(i + 1, j + 2));
          v.push_back(make_pair(i + 2, j + 1));
          v.push_back(make_pair(i + 2, j + 2));
          a[i + 1][j] = 1 - a[i + 1][j];
          a[i + 1][j + 1] = 1 - a[i + 1][j + 1];
        }
      }
      if (m % 2 && a[i][m - 1]) {
        v.push_back(make_pair(i + 1, m));
        v.push_back(make_pair(i + 2, m - 1));
        v.push_back(make_pair(i + 2, m));
        a[i + 1][m - 2] = 1 - a[i + 1][m - 2];
        a[i + 1][m - 1] = 1 - a[i + 1][m - 1];
      }
    }
    for (int j = 0; j < m - 2; j++) {
      if (a[n - 2][j] && a[n - 1][j]) {
        v.push_back(make_pair(n - 1, j + 1));
        v.push_back(make_pair(n, j + 1));
        v.push_back(make_pair(n - 1, j + 2));
        a[n - 2][j + 1] = 1 - a[n - 2][j + 1];
      } else if (a[n - 2][j]) {
        v.push_back(make_pair(n - 1, j + 1));
        v.push_back(make_pair(n, j + 2));
        v.push_back(make_pair(n - 1, j + 2));
        a[n - 2][j + 1] = 1 - a[n - 2][j + 1];
        a[n - 1][j + 1] = 1 - a[n - 1][j + 1];
      } else if (a[n - 1][j]) {
        v.push_back(make_pair(n, j + 1));
        v.push_back(make_pair(n, j + 2));
        v.push_back(make_pair(n - 1, j + 2));
        a[n - 2][j + 1] = 1 - a[n - 2][j + 1];
        a[n - 1][j + 1] = 1 - a[n - 1][j + 1];
      }
    }
    if (a[n - 2][m - 2] + a[n - 1][m - 2] + a[n - 1][m - 1] + a[n - 2][m - 1] ==
        4) {
      v.push_back(make_pair(n - 1, m - 1));
      v.push_back(make_pair(n - 1, m));
      v.push_back(make_pair(n, m));
      v.push_back(make_pair(n, m - 1));
      v.push_back(make_pair(n - 1, m - 1));
      v.push_back(make_pair(n - 1, m));
      v.push_back(make_pair(n, m));
      v.push_back(make_pair(n, m - 1));
      v.push_back(make_pair(n - 1, m - 1));
      v.push_back(make_pair(n - 1, m));
      v.push_back(make_pair(n, m));
      v.push_back(make_pair(n, m - 1));
    } else if (a[n - 2][m - 2] + a[n - 1][m - 2] + a[n - 1][m - 1] +
                   a[n - 2][m - 1] ==
               2) {
      flag = 1;
      if (a[n - 2][m - 2] == 1) {
        if (flag) {
          v.push_back(make_pair(n - 1, m - 1));
          a[n - 2][m - 2] = 1 - a[n - 2][m - 2];
          flag = 0;
        }
      } else {
        v.push_back(make_pair(n - 1, m - 1));
        a[n - 2][m - 2] = 1 - a[n - 2][m - 2];
      }
      if (a[n - 1][m - 2] == 1) {
        if (flag) {
          v.push_back(make_pair(n, m - 1));
          a[n - 1][m - 2] = 1 - a[n - 1][m - 2];
          flag = 0;
        }
      } else {
        v.push_back(make_pair(n, m - 1));
        a[n - 1][m - 2] = 1 - a[n - 1][m - 2];
      }
      if (a[n - 2][m - 1] == 1) {
        if (flag) {
          v.push_back(make_pair(n - 1, m));
          a[n - 2][m - 1] = 1 - a[n - 2][m - 1];
          flag = 0;
        }
      } else {
        v.push_back(make_pair(n - 1, m));
        a[n - 2][m - 1] = 1 - a[n - 2][m - 1];
      }
      if (a[n - 1][m - 1] == 1) {
        if (flag) {
          v.push_back(make_pair(n, m));
          a[n - 1][m - 1] = 1 - a[n - 1][m - 1];
          flag = 0;
        }
      } else {
        v.push_back(make_pair(n, m));
        a[n - 1][m - 1] = 1 - a[n - 1][m - 1];
      }
    }
    if (a[n - 2][m - 2] + a[n - 1][m - 2] + a[n - 1][m - 1] + a[n - 2][m - 1] ==
        3) {
      if (a[n - 2][m - 2] == 1) v.push_back(make_pair(n - 1, m - 1));
      if (a[n - 2][m - 1] == 1) v.push_back(make_pair(n - 1, m));
      if (a[n - 1][m - 1] == 1) v.push_back(make_pair(n, m));
      if (a[n - 1][m - 2] == 1) v.push_back(make_pair(n, m - 1));
    }
    if (a[n - 2][m - 2] + a[n - 1][m - 2] + a[n - 1][m - 1] + a[n - 2][m - 1] ==
        1) {
      if (a[n - 2][m - 2] == 1) {
        v.push_back(make_pair(n - 1, m - 1));
        v.push_back(make_pair(n - 1, m));
        v.push_back(make_pair(n, m));
        v.push_back(make_pair(n, m - 1));
        v.push_back(make_pair(n - 1, m - 1));
        v.push_back(make_pair(n - 1, m));
        v.push_back(make_pair(n, m));
        v.push_back(make_pair(n, m - 1));
        v.push_back(make_pair(n - 1, m - 1));
      }
      if (a[n - 1][m - 2] == 1) {
        v.push_back(make_pair(n, m - 1));
        v.push_back(make_pair(n - 1, m - 1));
        v.push_back(make_pair(n - 1, m));
        v.push_back(make_pair(n, m));
        v.push_back(make_pair(n, m - 1));
        v.push_back(make_pair(n - 1, m - 1));
        v.push_back(make_pair(n - 1, m));
        v.push_back(make_pair(n, m));
        v.push_back(make_pair(n, m - 1));
      }
      if (a[n - 2][m - 1] == 1) {
        v.push_back(make_pair(n - 1, m - 1));
        v.push_back(make_pair(n - 1, m));
        v.push_back(make_pair(n, m));
        v.push_back(make_pair(n, m - 1));
        v.push_back(make_pair(n - 1, m - 1));
        v.push_back(make_pair(n - 1, m));
        v.push_back(make_pair(n - 1, m));
        v.push_back(make_pair(n, m));
        v.push_back(make_pair(n, m - 1));
      }
      if (a[n - 1][m - 1] == 1) {
        v.push_back(make_pair(n - 1, m - 1));
        v.push_back(make_pair(n - 1, m));
        v.push_back(make_pair(n, m));
        v.push_back(make_pair(n, m));
        v.push_back(make_pair(n, m - 1));
        v.push_back(make_pair(n - 1, m - 1));
        v.push_back(make_pair(n - 1, m));
        v.push_back(make_pair(n, m));
        v.push_back(make_pair(n, m - 1));
      }
    }
    printf("%d\n", v.size() / 3);
    for (int i = 0; i < v.size(); i++) {
      printf("%d %d ", v[i].first, v[i].second);
      if (i % 3 == 2) printf("\n");
    }
  }
  return 0;
}
