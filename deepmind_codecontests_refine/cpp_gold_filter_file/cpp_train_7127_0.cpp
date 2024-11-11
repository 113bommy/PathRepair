#include <bits/stdc++.h>
using namespace std;
int cost[55][55];
int n, max_match;
int lx[55], ly[55];
int xy[55];
int yx[55];
bool S[55], T[55];
int slack[55];
int slackx[55];
int Prev[55];
void init_labels() {
  memset(lx, 0, sizeof(lx));
  memset(ly, 0, sizeof(ly));
  for (int x = 0; x < n; x++)
    for (int y = 0; y < n; y++) lx[x] = max(lx[x], cost[x][y]);
}
void update_labels() {
  int x, y, delta = 100000000;
  for (y = 0; y < n; y++)
    if (!T[y]) delta = min(delta, slack[y]);
  for (x = 0; x < n; x++)
    if (S[x]) lx[x] -= delta;
  for (y = 0; y < n; y++)
    if (T[y]) ly[y] += delta;
  for (y = 0; y < n; y++)
    if (!T[y]) slack[y] -= delta;
}
void add_to_tree(int x, int prevx) {
  S[x] = true;
  Prev[x] = prevx;
  for (int y = 0; y < n; y++)
    if (lx[x] + ly[y] - cost[x][y] < slack[y]) {
      slack[y] = lx[x] + ly[y] - cost[x][y];
      slackx[y] = x;
    }
}
void augment() {
  if (max_match == n) return;
  int x, y, root;
  int q[55], wr = 0, rd = 0;
  memset(S, false, sizeof(S));
  memset(T, false, sizeof(T));
  memset(Prev, -1, sizeof(Prev));
  for (x = 0; x < n; x++)
    if (xy[x] == -1) {
      q[wr++] = root = x;
      Prev[x] = -2;
      S[x] = true;
      break;
    }
  for (y = 0; y < n; y++) {
    slack[y] = lx[root] + ly[y] - cost[root][y];
    slackx[y] = root;
  }
  while (true) {
    while (rd < wr) {
      x = q[rd++];
      for (y = 0; y < n; y++)
        if (cost[x][y] == lx[x] + ly[y] && !T[y]) {
          if (yx[y] == -1) break;
          T[y] = true;
          q[wr++] = yx[y];
          add_to_tree(yx[y], x);
        }
      if (y < n) break;
    }
    if (y < n) break;
    update_labels();
    wr = rd = 0;
    for (y = 0; y < n; y++)
      if (!T[y] && slack[y] == 0) {
        if (yx[y] == -1) {
          x = slackx[y];
          break;
        } else {
          T[y] = true;
          if (!S[yx[y]]) {
            q[wr++] = yx[y];
            add_to_tree(yx[y], slackx[y]);
          }
        }
      }
    if (y < n) break;
  }
  if (y < n) {
    max_match++;
    for (int cx = x, cy = y, ty; cx != -2; cx = Prev[cx], cy = ty) {
      ty = xy[cx];
      yx[cy] = cx;
      xy[cx] = cy;
    }
    augment();
  }
}
int hungarian() {
  int ret = 0;
  max_match = 0;
  memset(xy, -1, sizeof(xy));
  memset(yx, -1, sizeof(yx));
  init_labels();
  augment();
  for (int x = 0; x < n; x++) ret += cost[x][xy[x]];
  return ret;
}
int code(char ch) {
  if (ch >= 'A' && ch <= 'Z')
    return ch - 'A' + 26;
  else
    return ch - 'a';
}
char decode(int x) {
  if (x < 26)
    return x + 'a';
  else
    return x - 26 + 'A';
}
int main() {
  int nn;
  scanf("%d%d", &nn, &n);
  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 0; i < nn; i++) {
    cost[code(s1[i])][code(s2[i])]++;
  }
  printf("%d\n", hungarian());
  for (int i = 0; i < n; i++) {
    printf("%c", decode(xy[i]));
  }
  printf("\n");
  return 0;
}
