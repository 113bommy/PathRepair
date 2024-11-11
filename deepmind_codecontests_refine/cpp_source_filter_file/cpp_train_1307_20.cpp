#include <bits/stdc++.h>
using namespace std;
const int N = 20;
char c[N][N][2];
char chx[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
char chy[] = {'C', 'D', 'H', 'S'};
int n, m, j1x = 17, j1y = 17, j2x = 17, j2y = 17;
map<pair<char, char>, bool> been;
bool check(int x1, int y1, int x2, int y2) {
  int cnt1 = 0, cnt2 = 0;
  bool ok1 = true, ok2 = true;
  map<char, bool> make_pair;
  make_pair.clear();
  char h = c[x1][y1][1];
  for (int i = x1; i < x1 + 3; i++) {
    for (int j = y1; j < y1 + 3; j++) {
      if (h != c[i][j][1]) ok1 = false;
      make_pair[c[i][j][0]] = true;
    }
  }
  cnt1 = make_pair.size();
  h = c[x2][y2][1];
  make_pair.clear();
  for (int i = x2; i < x2 + 3; i++) {
    for (int j = y2; j < y2 + 3; j++) {
      if (h != c[i][j][1]) ok2 = false;
      make_pair[c[i][j][0]] = true;
    }
  }
  cnt2 = make_pair.size();
  return (cnt1 == 9 && cnt2 == 9) || (ok1 && ok2);
}
void solve(int i, int j, int ii, int jj) {
  if (j1x != 17 || j2x != 17) {
    for (int k1 = 0; k1 < 13; k1++) {
      for (int k2 = 0; k2 < 4; k2++) {
        if (!been[make_pair(chx[k1], chy[k2])]) {
          for (int l1 = 0; l1 < 13; l1++) {
            for (int l2 = 0; l2 < 4; l2++) {
              if (!been[make_pair(chx[l1], chy[l2])] &&
                  (k1 != l1 || k2 != l2)) {
                c[j1x][j1y][0] = chx[k1];
                c[j1x][j1y][1] = chy[k2];
                c[j2x][j2y][0] = chx[l1];
                c[j2x][j2y][1] = chy[l2];
                if (check(i, j, ii, jj)) {
                  printf("Solution exists.\n");
                  if (j1x != 17 && j2x != 17)
                    printf("Replace J1 with %c%c and J2 with %c%c.\n", chx[k1],
                           chy[k2], chx[l1], chy[l1]);
                  else if (j2x != 17)
                    printf("Replace J2 with %c%c.\n", chx[l1], chy[l1]);
                  else if (j1x != 17)
                    printf("Replace J1 with %c%c.\n", chx[k1], chy[k2]);
                  printf("Put the first square to (%d, %d).\n", i + 1, j + 1);
                  printf("Put the second square to (%d, %d).\n", ii + 1,
                         jj + 1);
                  exit(0);
                }
              }
            }
          }
        }
      }
    }
  } else if (check(i, j, ii, jj)) {
    printf("Solution exists.\nThere are no jokers.\n");
    printf("Put the first square to (%d, %d).\n", i + 1, j + 1);
    printf("Put the second square to (%d, %d).\n", ii + 1, jj + 1);
    exit(0);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c[i][j][0] >> c[i][j][1];
      been[make_pair(c[i][j][0], c[i][j][1])] = true;
      if (c[i][j][0] == 'J' && c[i][j][1] == '1') j1x = i, j1y = j;
      if (c[i][j][0] == 'J' && c[i][j][1] == '2') j2x = i, j2y = j;
    }
  }
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m - 2; j++) {
      for (int ii = 0; ii < n - 2; ii++) {
        for (int jj = 0; jj < m - 2; jj++) {
          if (ii == i && jj == j) continue;
          if (abs(i - ii) <= 2 && abs(j - jj) <= 2) continue;
          solve(i, j, ii, jj);
        }
      }
    }
  }
  cout << "No solution.\n";
  return 0;
}
