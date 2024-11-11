#include <bits/stdc++.h>
using namespace std;
template <class T>
void chkmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
void chkmin(T &a, T b) {
  if (a > b) a = b;
}
int n, k;
char s[2000010], t[2000010];
int vis[60];
char c[60];
int cost[60][60], max_match;
int lx[60], ly[60], xy[60], yx[60];
bool S[60], T[60];
int slack[60], slackx[60], prv[60], q[60];
void init_labels() {
  memset(lx, 0, sizeof lx);
  memset(ly, 0, sizeof ly);
  for (int x = 0; x < k; x++) {
    for (int y = 0; y < k; y++) lx[x] = max(lx[x], cost[x][y]);
  }
}
void update_labels() {
  int x, y, delta = 1000000000;
  for (y = 0; y < k; y++)
    if (!T[y]) delta = min(delta, slack[y]);
  for (x = 0; x < k; x++)
    if (S[x]) lx[x] -= delta;
  for (y = 0; y < k; y++) {
    if (T[y])
      ly[y] += delta;
    else
      slack[y] -= delta;
  }
}
void add_to_tree(int x, int prvx) {
  S[x] = 1;
  prv[x] = prvx;
  for (int y = 0; y < k; y++) {
    if (lx[x] + ly[y] - cost[x][y] < slack[y]) {
      slack[y] = lx[x] + ly[y] - cost[x][y];
      slackx[y] = x;
    }
  }
}
void augment() {
  if (max_match == k) return;
  int x, y, root;
  int wr = 0, rd = 0;
  memset(S, 0, sizeof S);
  memset(T, 0, sizeof T);
  memset(prv, -1, sizeof prv);
  for (x = 0; x < k; x++)
    if (xy[x] == -1) break;
  q[wr++] = root = x;
  prv[x] = -2;
  S[x] = 1;
  for (y = 0; y < k; y++) {
    slack[y] = lx[root] + ly[y] - cost[root][y];
    slackx[y] = root;
  }
  while (1) {
    while (rd < wr) {
      x = q[rd++];
      for (y = 0; y < k; y++) {
        if (cost[x][y] == lx[x] + ly[y] && !T[y]) {
          if (yx[y] == -1) break;
          T[y] = 1;
          q[wr++] = yx[y];
          add_to_tree(yx[y], x);
        }
      }
      if (y < k) break;
    }
    if (y < k) break;
    update_labels();
    wr = rd = 0;
    for (y = 0; y < k; y++) {
      if (!T[y] && !slack[y]) {
        if (yx[y] == -1) {
          x = slackx[y];
          break;
        } else {
          T[y] = 1;
          if (!S[yx[y]]) {
            q[wr++] = yx[y];
            add_to_tree(yx[y], slackx[y]);
          }
        }
      }
    }
    if (y < k) break;
  }
  if (y < k) {
    max_match++;
    for (int cx = x, cy = y, ty; cx != -2; cx = prv[cx], cy = ty) {
      ty = xy[cx];
      yx[cy] = cx;
      xy[cx] = cy;
    }
    augment();
  }
}
int hungarian() {
  max_match = 0;
  memset(xy, -1, sizeof xy);
  memset(yx, -1, sizeof yx);
  init_labels();
  augment();
  int rlt = 0;
  for (int x = 0; x < k; x++) rlt += cost[x][xy[x]];
  return rlt;
}
int func(char x) {
  if (x >= 'a') return x - 'a';
  return x - 'A' + 26;
}
char defunc(int i) {
  if (i < 26) return 'a' + i;
  return 'A' + i;
}
int main() {
  scanf("%d%d%s%s", &n, &k, s, t);
  int cnt = 0;
  memset(vis, -1, sizeof vis);
  for (int i = 0; i < n; i++) vis[func(s[i])] = 1;
  for (int i = 0; i < 52; i++) {
    if (vis[i]) vis[i] = cnt, c[cnt++] = defunc(i);
  }
  for (int i = 0; i < n; i++) {
    int l = func(s[i]), r = func(t[i]);
    cost[vis[l]][vis[r]]++;
  }
  cout << hungarian() << endl;
  for (int i = 0; i < k; i++) putchar(c[xy[i]]);
  return 0;
}
