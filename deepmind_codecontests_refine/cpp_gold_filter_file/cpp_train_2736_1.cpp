#include <bits/stdc++.h>
using namespace std;
int t;
int n, m;
char grid[105][105];
vector<pair<int, int> > ans;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        scanf(" %c", &grid[i][j]);
      }
    }
    ans.clear();
    for (int i = n - 1; i >= 0; i -= 2) {
      for (int j = m - 1; j >= 0; j -= 2) {
        if (i == 0) i = 1;
        if (j == 0) j = 1;
        vector<pair<int, int> > ones, zeroes;
        if (grid[i][j] == '1')
          ones.push_back(pair<int, int>(i, j));
        else
          zeroes.push_back(pair<int, int>(i, j));
        if (grid[i + 1][j] == '1')
          ones.push_back(pair<int, int>(i + 1, j));
        else
          zeroes.push_back(pair<int, int>(i + 1, j));
        if (grid[i][j + 1] == '1')
          ones.push_back(pair<int, int>(i, j + 1));
        else
          zeroes.push_back(pair<int, int>(i, j + 1));
        if (grid[i + 1][j + 1] == '1')
          ones.push_back(pair<int, int>(i + 1, j + 1));
        else
          zeroes.push_back(pair<int, int>(i + 1, j + 1));
        if (ones.size() == 0)
          continue;
        else if (ones.size() == 1) {
          ans.push_back(pair<int, int>(ones[0]));
          ans.push_back(pair<int, int>(zeroes[0]));
          ans.push_back(pair<int, int>(zeroes[1]));
          ans.push_back(pair<int, int>(ones[0]));
          ans.push_back(pair<int, int>(zeroes[1]));
          ans.push_back(pair<int, int>(zeroes[2]));
          ans.push_back(pair<int, int>(ones[0]));
          ans.push_back(pair<int, int>(zeroes[0]));
          ans.push_back(pair<int, int>(zeroes[2]));
        } else if (ones.size() == 2) {
          ans.push_back(pair<int, int>(ones[0]));
          ans.push_back(pair<int, int>(zeroes[0]));
          ans.push_back(pair<int, int>(zeroes[1]));
          ans.push_back(pair<int, int>(ones[1]));
          ans.push_back(pair<int, int>(zeroes[0]));
          ans.push_back(pair<int, int>(zeroes[1]));
        } else if (ones.size() == 3) {
          ans.push_back(pair<int, int>(ones[0]));
          ans.push_back(pair<int, int>(ones[1]));
          ans.push_back(pair<int, int>(ones[2]));
        } else {
          ans.push_back(pair<int, int>(ones[0]));
          ans.push_back(pair<int, int>(ones[1]));
          ans.push_back(pair<int, int>(ones[2]));
          ans.push_back(pair<int, int>(ones[1]));
          ans.push_back(pair<int, int>(ones[2]));
          ans.push_back(pair<int, int>(ones[3]));
          ans.push_back(pair<int, int>(ones[2]));
          ans.push_back(pair<int, int>(ones[3]));
          ans.push_back(pair<int, int>(ones[0]));
          ans.push_back(pair<int, int>(ones[3]));
          ans.push_back(pair<int, int>(ones[0]));
          ans.push_back(pair<int, int>(ones[1]));
        }
        grid[i][j] = '0';
        grid[i][j + 1] = '0';
        grid[i + 1][j] = '0';
        grid[i + 1][j + 1] = '0';
      }
    }
    printf("%d\n", ans.size() / 3);
    for (int i = 0; i < ans.size(); i++) {
      printf("%d %d ", ans[i].first, ans[i].second);
      if (i % 3 == 2) printf("\n");
    }
  }
  return 0;
}
