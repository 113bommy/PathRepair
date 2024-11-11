#include <bits/stdc++.h>
using namespace std;
struct Node {};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int k = 0;
int n = 2001 - 1;
char grid[2001][2001];
void connect(int x, int y) {
  grid[x][y] = 'Y';
  grid[y][x] = 'Y';
  return;
}
int main() {
  scanf("%d", &k);
  for (int i = 0; i < n; i++) {
    int j = 0;
    for (j = 0; j < n; j++) {
      grid[i][j] = 'N';
    }
    grid[i][j] = '\0';
  }
  int base = 10;
  vector<int> exp;
  vector<int> extra;
  exp.clear();
  extra.clear();
  while (true) {
    int e = int(log10(double(k)));
    if (e < 2) {
      break;
    }
    exp.push_back(e);
    extra.push_back(k / pow(base, e - 1));
    k -= (int)pow(base, e - 1) * (int)(k / pow(base, e - 1));
  }
  int layer;
  if (exp.size() == 0) {
    layer = 1;
  } else {
    layer = exp[0] * 2 - 1;
  }
  int anchor = 0;
  int pos = 2;
  for (int i = 0; i < exp.size(); i++) {
    anchor = 0;
    int e = exp[i];
    for (int j = 0; j < layer - (e * 2 - 1); j++) {
      connect(anchor, pos);
      anchor = pos;
      pos++;
    }
    for (int j = 1; j <= e; j++) {
      if (j == e) {
        for (int b = 0; b < extra[i]; b++) {
          connect(anchor, pos + b);
        }
        for (int b = 0; b < extra[i]; b++) {
          connect(1, pos + b);
        }
        pos += extra[i];
      } else {
        for (int b = 0; b < base; b++) {
          connect(anchor, pos + b);
        }
        anchor = pos + base;
        for (int b = 0; b < base; b++) {
          connect(anchor, pos + b);
        }
        pos = anchor + 1;
      }
    }
  }
  if (k > 0) {
    anchor = 0;
    for (int i = 0; i < layer - 1; i++) {
      connect(anchor, pos);
      anchor = pos;
      pos += 1;
    }
    for (int j = 0; j < k; j++) {
      connect(anchor, pos);
      connect(1, pos);
      pos++;
    }
  }
  printf("%d\n", pos);
  for (int i = 0; i < pos; i++) {
    for (int j = 0; j < pos; j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }
  return 0;
}
