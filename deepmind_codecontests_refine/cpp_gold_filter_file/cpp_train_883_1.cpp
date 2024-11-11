#include <bits/stdc++.h>
using namespace std;
struct node {
  int num, path;
};
queue<node> q;
bool jud[500] = {false};
int G[500][500] = {0};
int main() {
  int n, m, a, b;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);
    G[a][b] = G[b][a] = 1;
  }
  node temp, temp2;
  if (G[1][n] == 1) {
    bool flag = false;
    temp.num = 1;
    temp.path = 0;
    q.push(temp);
    while (!q.empty()) {
      temp = q.front();
      q.pop();
      for (int i = 1; i <= n; i++)
        if (temp.num != i && G[temp.num][i] == 0 && jud[i] == false) {
          if (i == n) {
            flag = true;
            printf("%d\n", temp.path + 1);
            break;
          } else {
            temp2.num = i;
            temp2.path = temp.path + 1;
            jud[i] = true;
            q.push(temp2);
          }
        }
      if (flag == true) break;
    }
    if (flag == false) {
      printf("-1\n");
    }
  } else {
    bool flag = false;
    temp.num = 1;
    temp.path = 0;
    q.push(temp);
    while (!q.empty()) {
      temp = q.front();
      q.pop();
      for (int i = 1; i <= n; i++)
        if (G[temp.num][i] == 1 && jud[i] == false) {
          if (i == n) {
            flag = true;
            printf("%d\n", temp.path + 1);
            break;
          } else {
            temp2.num = i;
            temp2.path = temp.path + 1;
            jud[i] = true;
            q.push(temp2);
          }
        }
      if (flag == true) break;
    }
    if (flag == false) {
      printf("-1\n");
    }
  }
  return 0;
}
