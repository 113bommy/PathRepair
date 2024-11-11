#include <bits/stdc++.h>
using namespace std;
int n, m, mem[300006][5][6], ck[6], mem2[300006][5][6];
char a[300003];
vector<int> b[300003], t1, t2;
int dp(int i = 0, int p1 = 4, int p2 = 5) {
  if (i == m) return 0;
  int& ret = mem[i][p1][p2];
  if (~ret) return ret;
  ret = 1e9;
  int x, y, c1, c2;
  for (int u = 0; u <= 2; u++)
    for (int k = u + 1; k <= 3; k++) {
      if (p1 != u && p2 != u && p1 != k && p2 != k) {
        c1 = 0, c2 = 0;
        x = u, y = k;
        for (int j = 1; j <= n; j++) {
          if (j % 2 == 1) {
            if (b[j][i] != x) c1++;
            if (b[j][i] != y) c2++;
          } else {
            if (b[j][i] != y) c1++;
            if (b[j][i] != x) c2++;
          }
        }
        ret = min(ret, dp(i + 1, u, k) + c1);
        ret = min(ret, dp(i + 1, k, u) + c2);
      }
    }
  return ret;
}
int dp2(int i = 1, int p1 = 4, int p2 = 5) {
  if (i == n + 1) return 0;
  int& ret = mem2[i][p1][p2];
  if (~ret) return ret;
  ret = 1e9;
  int x, y, c1, c2;
  for (int u = 0; u <= 2; u++)
    for (int k = u + 1; k <= 3; k++) {
      if (p1 != u && p2 != u && p1 != k && p2 != k) {
        c1 = 0, c2 = 0;
        x = u, y = k;
        for (int j = 0; j <= m - 1; j++) {
          if (j % 2 == 1) {
            if (b[i][j] != x) c1++;
            if (b[i][j] != y) c2++;
          } else {
            if (b[i][j] != y) c1++;
            if (b[i][j] != x) c2++;
          }
        }
        ret = min(ret, dp2(i + 1, u, k) + c1);
        ret = min(ret, dp2(i + 1, k, u) + c2);
      }
    }
  return ret;
}
void bulid(int i = 0, int p1 = 4, int p2 = 5) {
  if (i == m) return;
  int x, y, c1, c2, h = 0;
  for (int u = 0; u <= 2; u++) {
    for (int k = u + 1; k <= 3; k++) {
      if (p1 != u && p2 != u && p1 != k && p2 != k) {
        c1 = 0, c2 = 0;
        x = u, y = k;
        for (int j = 1; j <= n; j++) {
          if (j % 2 == 1) {
            if (b[j][i] != x) c1++;
            if (b[j][i] != y) c2++;
          } else {
            if (b[j][i] != y) c1++;
            if (b[j][i] != x) c2++;
          }
        }
        if (dp(i, p1, p2) == dp(i + 1, u, k) + c1) {
          t1.push_back(u);
          t2.push_back(k);
          bulid(i + 1, u, k);
          h = 1;
          break;
        }
        if (dp(i, p1, p2) == dp(i + 1, k, u) + c2) {
          t1.push_back(k);
          t2.push_back(u);
          bulid(i + 1, k, u);
          h = 1;
          break;
        }
      }
    }
    if (h) break;
  }
}
void bulid2(int i = 1, int p1 = 4, int p2 = 5) {
  if (i == n + 1) return;
  int x, y, c1, c2, h = 0;
  for (int u = 0; u <= 2; u++) {
    for (int k = u + 1; k <= 3; k++) {
      if (p1 != u && p2 != u && p1 != k && p2 != k) {
        c1 = 0, c2 = 0;
        x = u, y = k;
        for (int j = 0; j <= m - 1; j++) {
          if (j % 2 == 1) {
            if (b[i][j] != x) c1++;
            if (b[i][j] != y) c2++;
          } else {
            if (b[i][j] != y) c1++;
            if (b[i][j] != x) c2++;
          }
        }
        if (dp2(i, p1, p2) == dp2(i + 1, u, k) + c1) {
          t1.push_back(u);
          t2.push_back(k);
          bulid2(i + 1, u, k);
          h = 1;
          break;
        }
        if (dp2(i, p1, p2) == dp2(i + 1, k, u) + c2) {
          t1.push_back(k);
          t2.push_back(u);
          bulid2(i + 1, k, u);
          h = 1;
          break;
        }
      }
    }
    if (h) break;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", &a);
    for (int j = 0; j <= m - 1; j++) {
      if (a[j] == 'A')
        b[i].push_back(0);
      else if (a[j] == 'G')
        b[i].push_back(1);
      else if (a[j] == 'C')
        b[i].push_back(2);
      else
        b[i].push_back(3);
    }
  }
  memset(mem, -1, sizeof mem);
  int ans = dp();
  memset(mem2, -1, sizeof mem2);
  int ans2 = dp2();
  if (ans <= ans2) {
    bulid();
    for (int i = 1; i <= n; i++) {
      if (i % 2 == 1) {
        for (auto p : t1) {
          if (p == 0)
            printf("A");
          else if (p == 1)
            printf("G");
          else if (p == 2)
            printf("C");
          else if (p == 3)
            printf("T");
        }
      } else {
        for (auto p : t2) {
          if (p == 0)
            printf("A");
          else if (p == 1)
            printf("G");
          else if (p == 2)
            printf("C");
          else if (p == 3)
            printf("T");
        }
      }
      printf("\n");
    }
  } else {
    bulid2();
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= m - 1; j++) {
        if (j % 2 == 1) {
          int p = t1[i - 1];
          if (p == 0)
            printf("A");
          else if (p == 1)
            printf("G");
          else if (p == 2)
            printf("C");
          else if (p == 3)
            printf("T");
        } else {
          int p = t2[i - 1];
          if (p == 0)
            printf("A");
          else if (p == 1)
            printf("G");
          else if (p == 2)
            printf("C");
          else if (p == 3)
            printf("T");
        }
      }
      printf("\n");
    }
  }
  return 0;
}
