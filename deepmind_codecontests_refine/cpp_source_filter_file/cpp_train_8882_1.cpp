#include <bits/stdc++.h>
using namespace std;
struct chamber {
  int x;
  int y;
  int a;
};
int n, m;
string S[1010];
bool flag[1010][1010][4];
int step[1010][1010][4];
int Mx[4] = {0, -1, 0, 1};
int My[4] = {-1, 0, 1, 0};
queue<chamber> BFS;
bool cek(int a, int b) { return (a >= 0 && b >= 0 && a < n && b < n); }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) cin >> S[i];
  memset(flag, false, sizeof flag);
  memset(step, 0, sizeof step);
  chamber start;
  start.x = n - 1;
  start.y = m - 1;
  start.a = 0;
  BFS.push(start);
  flag[n - 1][m - 1][0] = true;
  while (!BFS.empty()) {
    chamber no = BFS.front();
    BFS.pop();
    chamber ne;
    ne.x = no.x + Mx[no.a];
    ne.y = no.y + My[no.a];
    ne.a = no.a;
    if (cek(ne.x, ne.y) && !flag[ne.x][ne.y][ne.a]) {
      flag[ne.x][ne.y][ne.a] = true;
      step[ne.x][ne.y][ne.a] = step[no.x][no.y][no.a];
      BFS.push(ne);
    }
    if (S[no.x][no.y] == '#') {
      ne.x = no.x;
      ne.y = no.y;
      ne.a = (no.a + 5) % 4;
      if (cek(ne.x, ne.y) && !flag[ne.x][ne.y][ne.a]) {
        flag[ne.x][ne.y][ne.a] = true;
        step[ne.x][ne.y][ne.a] = step[no.x][no.y][no.a] + 1;
        BFS.push(ne);
      }
      ne.x = no.x;
      ne.y = no.y;
      ne.a = (no.a + 3) % 4;
      if (cek(ne.x, ne.y) && !flag[ne.x][ne.y][ne.a]) {
        flag[ne.x][ne.y][ne.a] = true;
        step[ne.x][ne.y][ne.a] = step[no.x][no.y][no.a] + 1;
        BFS.push(ne);
      }
    }
  }
  if (!flag[0][0][0]) {
    puts("-1");
    return 0;
  }
  printf("%d", step[0][0][0]);
  puts("");
  return 0;
}
