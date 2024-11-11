#include <bits/stdc++.h>
using namespace std;
int s[105][105];
vector<string> arr;
char in[105];
int main() {
  int n, m, q;
  scanf("%d%d%d\n", &n, &m, &q);
  while (q--) {
    fgets(in, 100, stdin);
    arr.push_back(string(in));
  }
  for (int i = arr.size() - 1; i >= 0; i--) {
    int x, y, k;
    if (arr[i][0] == '3') {
      sscanf(&arr[i][1], "%d%d%d", &x, &y, &k);
      s[x][y] = k;
    }
    if (arr[i][0] == '1') {
      sscanf(&arr[i][1], "%d", &x);
      for (int j = m + 1; j > 1; j--) {
        s[x][j] = s[x][j - 1];
      }
      s[x][1] = s[x][m + 1];
    }
    if (arr[i][0] == '2') {
      sscanf(&arr[i][1], "%d", &x);
      for (int j = n + 1; j > 1; j--) {
        s[j][x] = s[j - 1][x];
      }
      s[1][x] = s[n + 1][x];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d ", s[i][j]);
    }
    puts("");
  }
}
