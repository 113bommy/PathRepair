#include <bits/stdc++.h>
using namespace std;
struct Node {
  int a, b, c, d;
} temp;
queue<Node> q1, q2;
string s1[305][305], s2[305][305];
int main() {
  int n, m;
  int ans = 0, m1 = 0, m2 = 0;
  int num1 = 0, num0 = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> s1[i][j];
      ans += 2 * s1[i][j].length();
      if (i == 1 && j == m) ans -= s1[i][j].length();
      if (i == n && j == 1) ans -= s1[i][j].length();
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> s2[i][j];
      ans += 2 * s2[i][j].length();
      if (i == 1 && j == m) ans -= s2[i][j].length();
      if (i == n && j == 1) ans -= s2[i][j].length();
    }
  printf("%d\n", ans);
  for (int i = 1; i < m; i++) {
    temp.a = 1;
    temp.b = m;
    for (int k = s1[1][i].size() - 1; k >= 0; k--) {
      printf("%d %d %d %d\n", 1, i, 1, m);
      if (s1[1][i][k] == '0') {
        temp.c = 1;
        temp.d = 1;
      } else {
        temp.c = n;
        temp.d = m;
      }
      q1.push(temp);
    }
  }
  for (int i = 2; i <= m; i++) {
    temp.a = n;
    temp.b = 1;
    for (int k = s1[n][i].size() - 1; k >= 0; k--) {
      printf("%d %d %d %d\n", n, i, n, 1);
      if (s1[n][i][k] == '0') {
        temp.c = 1;
        temp.d = 1;
      } else {
        temp.c = n;
        temp.d = m;
      }
      q2.push(temp);
    }
  }
  for (int i = s1[1][m].size() - 1; i >= 0; i--) {
    if (s1[1][m][i] == '0')
      printf("%d %d %d %d\n", 1, m, 1, 1);
    else
      printf("%d %d %d %d\n", 1, m, n, m);
  }
  while (!q1.empty()) {
    temp = q1.front();
    q1.pop();
    printf("%d %d %d %d\n", temp.a, temp.b, temp.c, temp.d);
  }
  for (int i = s1[n][1].size() - 1; i >= 0; i--) {
    if (s1[n][1][i] == '0')
      printf("%d %d %d %d\n", n, 1, 1, 1);
    else
      printf("%d %d %d %d\n", n, 1, n, m);
  }
  while (!q2.empty()) {
    temp = q2.front();
    q2.pop();
    printf("%d %d %d %d\n", temp.a, temp.b, temp.c, temp.d);
  }
  for (int i = 2; i < n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = s1[i][j].size() - 1; k >= 0; k--) {
        if (s1[i][j][k] == '0') {
          if (j != 1)
            printf("%d %d %d %d\n%d %d %d %d\n", i, j, 1, j, 1, j, 1, 1);
          else
            printf("%d %d %d %d\n%d %d %d %d\n", i, j, n, j, n, j, 1, 1);
        } else {
          if (j != m)
            printf("%d %d %d %d\n%d %d %d %d\n", i, j, n, j, n, j, n, m);
          else
            printf("%d %d %d %d\n%d %d %d %d\n", i, j, 1, j, 1, j, n, m);
        }
      }
  for (int i = 2; i < n; i++)
    for (int j = 1; j <= m; j++) {
      for (int k = s2[i][j].length() - 1; k >= 0; k--) {
        if (s2[i][j][k] == '0') {
          if (j == 1)
            printf("%d %d %d %d\n%d %d %d %d\n", 1, 1, n, j, n, j, i, j);
          else
            printf("%d %d %d %d\n%d %d %d %d\n", 1, 1, 1, j, 1, j, i, j);
        } else {
          if (j == m)
            printf("%d %d %d %d\n%d %d %d %d\n", n, m, 1, j, 1, j, i, j);
          else
            printf("%d %d %d %d\n%d %d %d %d\n", n, m, n, j, n, j, i, j);
        }
      }
    }
  for (int i = 1; i < m; i++) {
    temp.a = 1;
    temp.b = m;
    temp.c = 1;
    temp.d = i;
    for (int j = s2[1][i].length() - 1; j >= 0; j--) {
      if (s2[1][i][j] == '0')
        printf("%d %d %d %d\n", 1, 1, 1, m);
      else
        printf("%d %d %d %d\n", n, m, 1, m);
      q1.push(temp);
    }
  }
  for (int i = s2[1][m].length() - 1; i >= 0; i--) {
    if (s2[1][m][i] == '0')
      printf("%d %d %d %d\n", 1, 1, 1, m);
    else
      printf("%d %d %d %d\n", n, m, 1, m);
  }
  for (int i = 2; i <= m; i++) {
    temp.a = n;
    temp.b = 1;
    temp.c = n;
    temp.d = i;
    for (int j = s2[n][i].length() - 1; j >= 0; j--) {
      if (s2[n][i][j] == '0')
        printf("%d %d %d %d\n", 1, 1, n, 1);
      else
        printf("%d %d %d %d\n", n, m, n, 1);
      q2.push(temp);
    }
  }
  for (int i = s2[n][1].length() - 1; i >= 0; i--) {
    if (s2[n][1][i] == '0')
      printf("%d %d %d %d\n", 1, 1, n, 1);
    else
      printf("%d %d %d %d\n", n, m, n, 1);
  }
  while (!q1.empty()) {
    temp = q1.front();
    q1.pop();
    printf("%d %d %d %d\n", temp.a, temp.b, temp.c, temp.d);
  }
  while (!q2.empty()) {
    temp = q2.front();
    q2.pop();
    printf("%d %d %d %d\n", temp.a, temp.b, temp.c, temp.d);
  }
  return 0;
}
