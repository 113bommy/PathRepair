#include <bits/stdc++.h>
using namespace std;
char dp[1010][1010];
bool visited[1010][1010];
int label[1010][1010];
int cnt[1000010];
int n, m;
void visit(int i, int j, int l) {
  if (i < 0 or j < 0 or i >= n or j >= m or dp[i][j] == '*') return;
  visited[i][j] = true;
  label[i][j] = l;
  cnt[l]++;
  if (!visited[i][j + 1]) visit(i, j + 1, l);
  if (!visited[i][j - 1]) visit(i, j - 1, l);
  if (!visited[i - 1][j]) visit(i - 1, j, l);
  if (!visited[i + 1][j]) visit(i + 1, j, l);
}
int main(int argc, char *argv[]) {
  cin >> n >> m;
  for (int i = 0; i < n; i++) scanf("%s", dp[i]);
  ;
  int c = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (!visited[i][j] and dp[i][j] == '.') visit(i, j, c++);
  }
  for (int i = 0; i < n; i++, cout << endl) {
    for (int j = 0; j < m; j++) {
      if (dp[i][j] == '.')
        cout << '.';
      else {
        int ans = 0;
        set<int> s;
        if (i > 0) s.insert(label[i - 1][j]);
        if (j > 0) s.insert(label[i][j - 1]);
        if (i < n - 1) s.insert(label[i + 1][j]);
        if (j < m - 1) s.insert(label[i][j + 1]);
        for (typeof(s.begin()) it = s.begin(); it != s.end(); it++)
          ans = ans + cnt[*it];
        cout << (ans + 1) % 10;
      }
    }
  }
}
