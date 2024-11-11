#include <bits/stdc++.h>
using namespace std;
const int maxN = 405;
char s[maxN][maxN];
int s1[maxN][maxN], s2[maxN][maxN], s3[maxN][maxN], s4[maxN][maxN],
    kq[maxN][maxN];
int n, m, dem;
void nhap() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%s\n", s[i]);
  }
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < m + 1; j++) {
      s1[i][j] = s1[i][j - 1] + ('1' - s[i - 1][j - 1]);
      s2[i][j] = s2[i - 1][j] + ('1' - s[i - 1][j - 1]);
      s3[i][j] = s3[i - 1][j - 1] + ('1' - s[i - 1][j - 1]);
      s4[i][j] = s4[i - 1][j + 1] + ('1' - s[i - 1][j - 1]);
    }
}
bool kt(int x1, int y1, int x2, int y2) {
  if (x1 <= 0) return false;
  if (y1 <= 0) return false;
  if (x2 <= 0) return false;
  if (y2 <= 0) return false;
  if (x2 > n || x1 > n) return false;
  if (y2 > m || y1 > m) return false;
}
void init() {
  int dem = 0;
  for (int len = 1; len < min(n, m); len++)
    for (int i = 1; i < n + 1; i++)
      for (int j = 1; j < m + 1; j++) {
        int x1, y1, x2, y2;
        int tam = dem;
        x1 = i, y1 = j + len, x2 = i - len, y2 = j;
        if (kt(x1, y1, x2, y2))
          if (s1[x1][y1] - s1[i][j - 1] == len + 1 &&
              s2[i][j] - s2[x2 - 1][y2] == len + 1 &&
              s3[x1][y1] - s3[x2 - 1][y2 - 1] == len + 1)
            ++dem;
        x1 = i, y1 = j + len, x2 = i + len, y2 = j;
        if (kt(x1, y2, x2, y2))
          if (s1[x1][y1] - s1[i][j - 1] == len + 1 &&
              s2[x2][y2] - s2[i - 1][j] == len + 1 &&
              s4[x2][y2] - s4[x1 - 1][y1 + 1] == len + 1)
            ++dem;
        x1 = i, y1 = j - len, x2 = i + len, y2 = j;
        if (kt(x1, y2, x2, y2))
          if (s1[i][j] - s1[x1][y1 - 1] == len + 1 &&
              s2[x2][y2] - s2[i - 1][j] == len + 1 &&
              s3[x2][y2] - s3[x1 - 1][y1 - 1] == len + 1)
            ++dem;
        x1 = i, y1 = j - len, x2 = i - len, y2 = j;
        if (kt(x1, y2, x2, y2))
          if (s1[i][j] - s1[x1][y1 - 1] == len + 1 &&
              s2[i][j] - s2[x2 - 1][y2] == len + 1 &&
              s4[x1][y1] - s4[x2 - 1][y2 + 1] == len + 1)
            ++dem;
        x1 = i - len, y1 = j - len, x2 = i - len, y2 = j + len;
        if (kt(x1, y2, x2, y2))
          if (s1[x2][y2] - s1[x1][y1 - 1] == len * 2 + 1 &&
              s3[i][j] - s3[x1 - 1][y1 - 1] == len + 1 &&
              s4[i][j] - s4[x2 - 1][y2 + 1] == len + 1)
            ++dem;
        x1 = i - len, y1 = j - len, x2 = i + len, y2 = j - len;
        if (kt(x1, y2, x2, y2))
          if (s2[x2][y2] - s2[x1 - 1][y1] == len * 2 + 1 &&
              s3[i][j] - s3[x1 - 1][y1 - 1] == len + 1 &&
              s4[x2][y2] - s4[i - 1][j + 1] == len + 1)
            ++dem;
        x1 = i + len, y1 = j + len, x2 = i - len, y2 = j + len;
        if (kt(x1, y2, x2, y2))
          if (s2[x1][y1] - s2[x2 - 1][y2] == len * 2 + 1 &&
              s3[x1][y1] - s3[i - 1][j - 1] == len + 1 &&
              s4[i][j] - s4[x2 - 1][y2 + 1] == len + 1)
            ++dem;
        x1 = i + len, y1 = j + len, x2 = i + len, y2 = j - len;
        if (kt(x1, y2, x2, y2))
          if (s1[x1][y1] - s1[x2][y2 - 1] == len * 2 + 1 &&
              s3[x1][y1] - s3[i - 1][j - 1] == len + 1 &&
              s4[x2][y2] - s4[i - 1][j + 1] == len + 1)
            ++dem;
        kq[i][j] += dem - tam;
      }
  cout << dem;
}
void xuly() {}
int main() {
  nhap();
  init();
  xuly();
  return 0;
}
