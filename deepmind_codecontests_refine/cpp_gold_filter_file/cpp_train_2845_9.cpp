#include <bits/stdc++.h>
using namespace std;
int X[] = {0, 0, 1, 0, 0, -1};
int Y[] = {0, 1, 0, 0, -1, 0};
int Z[] = {1, 0, 0, -1, 0, 0};
struct node {
  int x, y;
  node() {}
  node(int x, int y) : x(x), y(y) {}
};
int p;
vector<int> v[100009], vec;
bool a[100004], flag[100008];
int b[100009];
int main() {
  memset(flag, 0, sizeof(flag));
  int i, j, k, l, n, m, x, y, z;
  for (i = 2; i <= 100005; i++) {
    if (flag[i] == 0) {
      v[i].push_back(i);
      for (j = i + i; j < 100005; j += i) {
        flag[j] = 1;
        v[j].push_back(i);
      }
    }
  }
  for (i = 2; i < 100003; i++)
    if (flag[i] == 0) v[i].push_back(i);
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  cin >> n >> m;
  char c;
  for (i = 1; i <= m; i++) {
    cin >> c >> x;
    if (c == '+') {
      y = 1;
      if (a[x])
        printf("Already on\n");
      else {
        y = 0;
        for (j = 0; j < v[x].size(); j++) {
          z = v[x][j];
          if (b[z]) {
            printf("Conflict with %d\n", b[z]);
            y = 1;
            break;
          }
        }
        if (!y) printf("Success\n");
      }
      for (j = 0; j < v[x].size() && !y; j++) {
        z = v[x][j];
        b[z] = x;
      }
      if (!y) a[x] = 1;
    } else {
      y = 0;
      if (!a[x])
        printf("Already off\n");
      else {
        printf("Success\n");
        y = 1;
      }
      for (j = 0; j < v[x].size() && y; j++) {
        z = v[x][j];
        b[z] = 0;
      }
      if (y) a[x] = 0;
    }
  }
  return 0;
}
