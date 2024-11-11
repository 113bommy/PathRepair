#include <bits/stdc++.h>
using namespace std;
int n, m;
char arr[500][500];
int dest1, dest2;
bool fnd = false;
bool x = true;
int beg1, beg2;
bool f = true;
void dfs(int i, int j) {
  if (i == dest1 && j == dest2) {
    fnd = true;
    return;
  }
  if (i == n || j == m || (arr[i][j] == 'X' && !f) || i < 0 || j < 0) return;
  f = false;
  arr[i][j] = 'X';
  dfs(i, j + 1);
  dfs(i + 1, j);
  dfs(i, j - 1);
  dfs(i - 1, j);
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  cin >> beg1 >> beg2;
  cin >> dest1 >> dest2;
  dest1--;
  dest2--;
  int cnt = 0;
  if (dest2 < m && (arr[dest1][dest2 + 1] == '.' ||
                    (dest1 == beg1 - 1 && dest2 + 1 == beg2 - 1)))
    cnt++;
  if (dest2 > 0 && (arr[dest1][dest2 - 1] == '.' ||
                    (dest1 == beg1 - 1 && dest2 - 1 == beg2 - 1)))
    cnt++;
  if (dest1 < n && (arr[dest1 + 1][dest2] == '.' ||
                    (dest1 + 1 == beg1 - 1 && dest2 == beg2 - 1)))
    cnt++;
  if (dest1 > 0 && (arr[dest1 - 1][dest2] == '.' ||
                    (dest1 - 1 == beg1 - 1 && dest2 == beg2 - 1)))
    cnt++;
  if ((cnt < 2 && arr[dest1][dest2] != 'X') ||
      (cnt < 1 && dest1 == beg1 - 1 && dest2 == beg2 - 1)) {
    cout << "NO";
    return 0;
  }
  dfs(beg1 - 1, beg2 - 1);
  if (fnd)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
