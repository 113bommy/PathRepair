#include <bits/stdc++.h>
using namespace std;
int n;
char m[55][55];
void judge(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > n || m[x][y] == '#') {
    puts("NO");
    exit(0);
  }
  m[x][y] = '#';
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%s", m[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (m[i][j] == '.')
        judge(i, j), judge(i + 1, j), (i + 2, j), judge(i + 1, j - 1),
            judge(i + 1, j + 1);
    }
  puts("YES");
  return 0;
}
