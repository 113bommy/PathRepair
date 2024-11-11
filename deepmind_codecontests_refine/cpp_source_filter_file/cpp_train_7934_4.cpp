#include <bits/stdc++.h>
using namespace std;
long long int dr[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
long long int dc[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
vector<string> initState(8);
bool dfs(long long int r, long long int c, long long int step) {
  if (step > 8) return 1;
  for (long long int i = 0; i < 8; ++i) {
    long long int row = r + dr[i];
    long long int col = c + dc[i];
    if (row < 0 || row >= 8 || col < 0 || col >= 8) continue;
    if (row >= step && initState[row - step][col] == 'S') continue;
    if (row > step && initState[row - step - 1][col] == 'S') continue;
    if (dfs(row, col, step + 1)) return 1;
  }
  return 0;
}
int main() {
  for (long long int i = 0; i < 8; ++i) cin >> initState[i];
  if (dfs(7, 0, 0))
    printf("WIN");
  else
    printf("LOSE");
}
