#include <bits/stdc++.h>
using namespace std;
struct Node {
  int num;
  int son[2];
} tre[6500005], tree[2500005];
map<string, int> maps;
string s, c;
int root[2][100005];
int cnt = 0, cntt = 0;
int init[2][35];
int add0(int x, int f, int y, int z) {
  ++cnt;
  int now = cnt;
  tre[now].num = tre[x].num + z;
  tre[now].son[0] = tre[x].son[0];
  tre[now].son[1] = tre[x].son[1];
  if (f < 30) {
    if (y < init[0][f])
      tre[now].son[0] = add0(tre[x].son[0], f + 1, y, z);
    else
      tre[now].son[1] = add0(tre[x].son[1], f + 1, y - init[0][f], z);
  }
  return now;
}
int add1(int x, int f, int y, int z) {
  ++cntt;
  int now = cntt;
  tree[now].son[0] = tree[x].son[0];
  tree[now].son[1] = tree[x].son[1];
  if (f < 20) {
    if (y < init[1][f])
      tree[now].son[0] = add1(tree[x].son[0], f + 1, y, z);
    else
      tree[now].son[1] = add1(tree[x].son[1], f + 1, y - init[1][f], z);
  } else
    tree[now].num = z;
  return now;
}
int ask0(int x, int y) {
  int ans = 0;
  for (int i = 0; i < 30; i++) {
    if (y < init[0][i])
      x = tre[x].son[0];
    else {
      ans += tre[tre[x].son[0]].num;
      y -= init[0][i];
      x = tre[x].son[1];
    }
  }
  ans += tre[x].num;
  return ans;
}
int ask1(int x, int y) {
  for (int i = 0; i < 20; i++) {
    if (y < init[1][i])
      x = tree[x].son[0];
    else {
      y -= init[1][i];
      x = tree[x].son[1];
    }
  }
  return tree[x].num;
}
int main() {
  int q, now, t = 0, gg, gl;
  cin >> q;
  init[0][29] = init[1][19] = 1;
  for (int i = 28; i >= 0; i--) init[0][i] = init[0][i + 1] * 2;
  for (int i = 18; i >= 0; i--) init[1][i] = init[1][i + 1] * 2;
  for (int i = 1; i <= q; i++) {
    cin >> c;
    if (c[0] == 'u') {
      cin >> now;
      root[0][i] = root[0][i - now - 1];
      root[1][i] = root[1][i - now - 1];
      continue;
    }
    cin >> s;
    if (!maps[s]) {
      t++;
      maps[s] = t;
    }
    gl = maps[s];
    root[0][i] = root[0][i - 1];
    root[1][i] = root[1][i - 1];
    gg = ask1(root[1][i], gl);
    if (c[0] == 's') {
      cin >> now;
      if (gg) root[0][i] = add0(root[0][i], 0, gg, -1);
      root[0][i] = add0(root[0][i], 0, now, 1);
      root[1][i] = add1(root[1][i], 0, gl, now);
    }
    if (c[0] == 'r') {
      if (gg) {
        root[0][i] = add0(root[0][i], 0, gg, -1);
        root[1][i] = add1(root[1][i], 0, gl, 0);
      }
    }
    if (c[0] == 'q') {
      if (gg)
        cout << ask0(root[0][i], gg - 1) << endl;
      else
        cout << "-1" << endl;
    }
  }
  return 0;
}
