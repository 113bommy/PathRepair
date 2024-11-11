#include <bits/stdc++.h>
using namespace std;
int row, column;
int **arr;
int **visited;
char *str;
typedef struct {
  int x;
  int y;
} position;
vector<position> pos;
int pos_size;
int count_paint = 0;
void DFS(int x, int y) {
  visited[x][y] = 1;
  if (x != (row - 1) && arr[x + 1][y] == 1 && visited[x + 1][y] == 0) {
    DFS(x + 1, y);
  }
  if (x != 0 && arr[x - 1][y] == 1 && visited[x - 1][y] == 0) {
    DFS(x - 1, y);
  }
  if (y != (column - 1) && arr[x][y + 1] == 1 && visited[x][y + 1] == 0) {
    DFS(x, y + 1);
  }
  if (y != 0 && arr[x][y - 1] == 1 && visited[x][y - 1] == 0) {
    DFS(x, y - 1);
  }
}
int check() {
  int flag = 0;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < column; j++) {
      if (arr[i][j] == 1 && visited[i][j] != 1) flag = 1;
      visited[i][j] = 0;
    }
  return flag;
}
int find() {
  pos_size = pos.size();
  for (int i = 0; i <= pos_size; i++) {
    arr[pos[i].x][pos[i].y] = 0;
    if (i == 0) {
      DFS(pos[i + 1].x, pos[i + 1].y);
      if (check()) return 1;
    } else {
      DFS(pos[i - 1].x, pos[i - 1].y);
      if (check()) return 1;
    }
    arr[pos[i].x][pos[i].y] = 1;
  }
  return 2;
}
int main() {
  scanf("%d %d", &row, &column);
  arr = (int **)calloc(row, sizeof(int *));
  visited = (int **)calloc(row, sizeof(int *));
  for (int i = 0; i < row; i++) {
    arr[i] = (int *)calloc(column, sizeof(int));
    visited[i] = (int *)calloc(column, sizeof(int));
  }
  char c;
  str = (char *)calloc(200, sizeof(char));
  for (int i = 0; i < row; i++) {
    scanf("%s", str);
    int c = strlen(str);
    if (c != column) {
      printf("%d %d %d", c, column, c == column);
      return 0;
      assert(c == column);
    }
    for (int j = 0; j < c; j++) {
      if (str[j] == '#') {
        arr[i][j] = 1;
        position pp;
        pp.x = i;
        pp.y = j;
        pos.push_back(pp);
        count_paint++;
      } else if (str[j] == '.') {
        arr[i][j] = 0;
      } else {
        printf(".....");
        assert(0);
      }
    }
  }
  if (count_paint <= 1)
    printf("-1\n");
  else if (count_paint <= 2) {
    printf("%d\n", 1);
  } else if (count_paint == 3) {
    printf("1\n");
  } else {
    printf("%d\n", find());
  }
}
