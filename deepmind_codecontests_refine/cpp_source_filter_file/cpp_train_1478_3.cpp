#include <bits/stdc++.h>
using namespace std;
const int N = 2020;
int n, x[N][N], row[N], col[N];
bool matchRow[N], matchCol[N];
char a[N][N], b[N][N], s[N];
vector<pair<bool, int>> out;
void solve() {
  memset(matchRow, true, sizeof(matchRow));
  memset(matchCol, true, sizeof(matchCol));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      x[i][j] = (a[i][j] != b[i][j]);
      matchCol[j] |= (x[i][j] != s[i] - '0');
      matchRow[i] |= (x[i][j] != s[j] - '0');
    }
  }
  bool diff = true;
  for (int t = 0; t < 100 && diff; ++t) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int sum = x[i][j];
        sum ^= ((row[i] & 1) && s[j] == '1');
        sum ^= ((col[j] & 1) && s[i] == '1');
        if (sum == 0) {
          continue;
        }
        if (s[i] == '1' && matchCol[j]) {
          col[j]++;
          out.push_back({0, j});
          matchRow[i] ^= 1;
          matchCol[j] ^= 1;
          continue;
        }
        if (s[j] == '1' && matchCol[j]) {
          row[i]++;
          out.push_back({1, i});
          matchRow[i] ^= 1;
          matchCol[j] ^= 1;
          continue;
        }
        if (s[i] == '1') {
          col[j]++;
          out.push_back({0, j});
          matchRow[i] ^= 1;
          matchCol[j] ^= 1;
          continue;
        }
        if (s[j] == '1') {
          row[i]++;
          out.push_back({1, i});
          matchRow[i] ^= 1;
          matchCol[j] ^= 1;
          continue;
        }
        cout << -1;
        return;
      }
    }
    diff = false;
    memset(matchRow, true, sizeof(matchRow));
    memset(matchCol, true, sizeof(matchCol));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        x[i][j] ^= ((row[i] & 1) && s[j] == '1');
        x[i][j] ^= ((col[j] & 1) && s[i] == '1');
        matchCol[j] |= (x[i][j] != s[i] - '0');
        matchRow[i] |= (x[i][j] != s[j] - '0');
        diff |= x[i][j];
      }
    }
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
  }
  if (diff) {
    cout << -1;
    return;
  }
  printf("%d\n", out.size());
  for (auto& p : out) {
    printf("%s %d\n", p.first ? "row" : "col", p.second);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", b[i]);
  }
  scanf("%s", s);
  solve();
  return 0;
}
