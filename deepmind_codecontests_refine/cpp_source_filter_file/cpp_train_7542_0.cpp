#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char ans[100][100], minn[100][100];
string A[10];
int F = false, MX, MY, visited[100][100], MINX = 99, MINY = 99;
void _clear() {
  int i, j;
  for (i = 0; i < (100); i++)
    for ((j) = (0); (j) < (100); (j)++) ans[i][j] = '.';
}
void _extreme() {
  int i, j;
  MINX = MINY = 0;
  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++) {
      if (minn[i][j] != '.') {
        MINX = (((MINX) > (i)) ? (MINX) : (i));
        MINY = (((MINY) > (j)) ? (MINY) : (j));
      }
    }
}
bool islesser() {
  int i, j;
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 100; j++) {
      if (ans[i][j] != minn[i][j]) {
        if (ans[i][j] < minn[i][j])
          return true;
        else
          return false;
      }
    }
  }
}
void update() {
  int i, j;
  if (islesser()) {
    F = true;
    for (i = 0; i < (100); i++) {
      for ((j) = (0); (j) < (100); (j)++) minn[i][j] = ans[i][j];
    }
    _extreme();
  }
}
void find_extreme() {
  int i, j;
  MX = MY = 0;
  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++) {
      if (ans[i][j] != '.') {
        MX = (((MX) > (i)) ? (MX) : (i));
        MY = (((MY) > (j)) ? (MY) : (j));
      }
    }
  for (i = 0; i < (MX + 1); i++) ans[i][MY + 1] = '\0';
}
pair<int, int> horizontal_write(int posx, int posy, int n) {
  int i, j, l = A[n].size();
  for (i = posy, j = 0; j < l; i++, j++) {
    if (ans[posx][i] != '.' && ans[posx][i] != A[n][j])
      return make_pair(-1, -1);
    ans[posx][i] = A[n][j];
  }
  return make_pair(posx, i - 1);
}
pair<int, int> vertical_write(int posx, int posy, int n) {
  int i, j, l = A[n].size();
  for (i = posx, j = 0; j < l; i++, j++) {
    if (ans[i][posy] != '.' && ans[i][posy] != A[n][j])
      return make_pair(-1, -1);
    ans[i][posy] = A[n][j];
  }
  return make_pair(i - 1, posy);
}
bool ispoxible(vector<int> v) {
  int i, j, k;
  pair<int, int> a, b, c;
  _clear();
  a = horizontal_write(0, 0, v[0]);
  if (a.first == -1) return false;
  a = vertical_write(a.first, a.second, v[2]);
  if (a.first == -1) return false;
  a = horizontal_write(a.first, a.second, v[5]);
  b = a;
  if (a.first == -1) return false;
  a = vertical_write(0, 0, v[1]);
  if (a.first == -1) return false;
  a = horizontal_write(a.first, a.second, v[3]);
  if (a.first == -1) return false;
  a = vertical_write(a.first, a.second, v[4]);
  c = a;
  if (a.first == -1) return false;
  if (b != c) return false;
  find_extreme();
  return true;
}
void dfs(int x, int y) {
  int x1, y1, i;
  visited[x][y] = true;
  for (i = 0; i < 4; i++) {
    x1 = x + dx[i];
    y1 = y + dy[i];
    if (x1 >= 0 && x1 <= MX && y1 >= 0 && y1 <= MY) {
      if (visited[x1][y1] == false && ans[x1][y1] == '.') dfs(x1, y1);
    }
  }
}
bool boobs() {
  int i, j, sum = 0;
  for (i = 0; i < (100); i++)
    for ((j) = (0); (j) < (100); (j)++) visited[i][j] = false;
  for (i = 0; i < (MX + 1); i++) {
    for ((j) = (0); (j) < (MY + 1); (j)++) {
      if (visited[i][j] == false && ans[i][j] == '.') {
        dfs(i, j);
        sum++;
      }
    }
  }
  return sum == 4;
}
void _print() {
  int i, j;
  for (i = 0; i <= MINX; i++) {
    for (j = 0; j <= MINY; j++) printf("%c", minn[i][j]);
    printf("\n");
    ;
  }
}
int main() {
  int i, j, k, n;
  vector<int> t, z;
  for (i = 0; i < (6); i++) cin >> A[i];
  for (i = 0; i < (6); i++) t.push_back(i);
  for (i = 0; i < (100); i++)
    for ((j) = (0); (j) < (100); (j)++) minn[i][j] = 'Z';
  sort(A, A + 6);
  do {
    if (ispoxible(t) && boobs()) {
      update();
    }
  } while (next_permutation((t).begin(), (t).end()));
  if (!F)
    printf("Impossible\n");
  else
    _print();
  return 0;
}
