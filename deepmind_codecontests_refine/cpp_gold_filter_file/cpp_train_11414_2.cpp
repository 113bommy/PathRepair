#include <bits/stdc++.h>
using namespace std;
const int MAX_COL = 1e3;
int cost[5];
bool e[5][MAX_COL + 10];
int nColumns;
int fullBits(int k) { return (1 << k) - 1; }
bool done(int mask) { return !((mask ^ fullBits(4)) & fullBits(4)); }
int startCleaner(int k) {
  int col = fullBits(k);
  int cleaner = 0;
  for (int j = 1; j <= k; j++) {
    cleaner += col << (4 * (j - 1));
  }
  return cleaner;
}
int moveDown(int cleaner) { return (cleaner << 1); }
int skipColumn(int mask) { return (mask >> 4); }
int merge(int cur, int next) { return (cur + (next << 4)); }
bool effective(int cleaner, int mask) {
  return (((cleaner | mask) ^ mask) & fullBits(4));
}
int download(int col) {
  int mask = 0;
  int shift = 0;
  for (int row = 1; row <= 4; row++) {
    mask += (e[row][col] << shift);
    shift++;
  }
  return mask;
}
void clean(int sum, int mask, set<pair<int, int> > &space) {
  if (done(mask)) {
    space.emplace(sum, skipColumn(mask));
  } else {
    for (int k = 1; k <= 3; k++) {
      int cleaner = startCleaner(k);
      for (int i = k; i <= 4; i++) {
        if (effective(cleaner, mask)) {
          clean(sum + cost[k], cleaner | mask, space);
        }
        cleaner = moveDown(cleaner);
      }
    }
  }
}
int memo[MAX_COL + 10][1 << 8];
int solve(int j, int mask) {
  if (memo[j][mask] == -1) {
    if (j > nColumns) {
      memo[j][mask] = 0;
    } else if (done(mask)) {
      memo[j][mask] = solve(j + 1, merge(skipColumn(mask), download(j + 2)));
    } else {
      memo[j][mask] =
          cost[4] + solve(j + 4, merge(download(j + 4), download(j + 5)));
      set<pair<int, int> > space;
      clean(0, mask + (download(j + 2) << 2 * 4), space);
      for (pair<int, int> sol : space) {
        memo[j][mask] =
            min(memo[j][mask], sol.first + solve(j + 1, sol.second));
      }
    }
  }
  return memo[j][mask];
}
int main() {
  cin >> nColumns;
  for (int i = 1; i <= 4; i++) {
    cin >> cost[i];
  }
  memset(e, true, sizeof(e));
  for (int i = 1; i <= 4; i++) {
    string row;
    cin >> row;
    for (int j = 1; j <= nColumns; j++) {
      e[i][j] = (row[j - 1] == '.' ? true : false);
    }
  }
  memset(memo, -1, sizeof(memo));
  cout << solve(1, merge(download(1), download(2))) << endl;
}
