#include <bits/stdc++.h>
using namespace std;
int m, n;
const int size = 1011;
struct node {
  int x, y, a;
} a[size * size];
bool cmp(node a, node s) { return a.a > s.a; }
vector<int> V[2][size];
int M[size][size];
int main() {
  cin >> n >> m;
  int num = 0;
  for (int i = 0; i < size; i++) V[0][i].clear(), V[1][i].clear();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      a[num].x = i;
      a[num].y = j;
      scanf("%d", &a[num].a);
      num++;
    }
  sort(a, a + num, cmp);
  memset(M, -1, sizeof(M));
  int i, ov = 1;
  for (i = 0; ov && i < num; i++) {
    int x = a[i].x, y = a[i].y;
    for (int i = 0; i < V[0][y].size(); i++)
      for (int j = 0; j < V[1][x].size(); j++)
        if (M[V[0][y][i]][V[1][x][j]] != -1) ov = 0;
    V[0][y].push_back(x);
    V[1][x].push_back(y);
    M[x][y] = 1;
  }
  cout << a[i - 1].a << endl;
}
