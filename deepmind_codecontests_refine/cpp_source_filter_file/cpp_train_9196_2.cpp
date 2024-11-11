#include <bits/stdc++.h>
using namespace std;
int n, k, d[2][100005];
char s[2][100005];
queue<int> q;
int main() {
  scanf("%d %d %s %s", &n, &k, s[0] + 1, s[1] + 1);
  q.push(0);
  q.push(1);
  memset(d, -1, sizeof(d));
  d[0][1] = 0;
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    int j = q.front();
    q.pop();
    if (j + k >= n) {
      printf("YES\n");
      return 0;
    }
    if (0 < j - 1 && j - 1 > d[i][j] + 1 && d[i][j - 1] == -1 &&
        s[i][j - 1] != 'X') {
      d[i][j - 1] = d[i][j] + 1;
      q.push(i);
      q.push(j - 1);
    }
    if (j + 1 > d[i][j] + 1 && d[i][j + 1] == -1 && s[i][j + 1] != 'X') {
      d[i][j + 1] = d[i][j] + 1;
      q.push(i);
      q.push(j + 1);
    }
    if (j + k > d[i][j] + 1 && d[1 - i][j + k] == -1 &&
        s[1 - i][j + k] != 'X') {
      d[1 - i][j + k] = d[i][j] + 1;
      q.push(1 - i);
      q.push(j + k);
    }
  }
  printf("NO\n");
  return 0;
}
