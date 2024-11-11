#include <bits/stdc++.h>
using namespace std;
const int maxn = 511;
bool vis[maxn][maxn] = {};
int N, M;
void Go(int &x, int &y, char c) {
  if (c == 'U') x--;
  if (c == 'D') x++;
  if (c == 'L') y--;
  if (c == 'R') y++;
  if (x < 1) x++;
  if (x > N) x--;
  if (y < 1) y++;
  if (y > M) y--;
}
char C[100011];
int main() {
  int x, y;
  cin >> N >> M >> x >> y;
  int Siz = N * M;
  scanf("%s", C + 1);
  int L = strlen(C + 1);
  for (int i = 0; i <= L; i++) {
    if (Siz == 0) {
      printf("0 ");
      continue;
    }
    int cnt;
    if (vis[x][y])
      cnt = 0;
    else {
      cnt = 1;
      vis[x][y] = 1;
      Siz--;
    }
    if (i != L)
      Go(x, y, C[i + 1]);
    else
      cnt += Siz;
    printf("%d ", cnt);
  }
  cout << endl;
  return 0;
}
