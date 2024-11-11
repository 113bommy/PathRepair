#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "Possible" : "Impossible");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  x += y;
  if (x >= mod) x -= mod;
}
void et() {
  puts("-1");
  exit(0);
}
int x[4], y[4];
pair<int, int> ans[4];
int ansVal = (1 << 30);
void ckeck(int len, int bx, int by) {
  int d[4];
  pair<int, int> tar[4];
  for (int(i) = 0; (i) < (int)(4); (i)++) d[i] = i;
  tar[0] = {bx, by};
  tar[1] = {bx + len, by};
  tar[2] = {bx, by + len};
  tar[3] = {bx + len, by + len};
  do {
    bool ok = 1;
    int tmp = 0;
    for (int(i) = 0; (i) < (int)(4); (i)++) {
      int id = d[i];
      if (x[id] != tar[i].first && y[id] != tar[i].second) {
        ok = 0;
        break;
      } else if (x[id] == tar[i].first) {
        tmp = max(tmp, abs(y[id] - tar[i].second));
      } else
        tmp = max(tmp, abs(x[id] - tar[i].first));
    }
    if (!ok) continue;
    if (tmp < ansVal) {
      ansVal = tmp;
      for (int(i) = 0; (i) < (int)(4); (i)++) ans[d[i]] = tar[i];
    }
  } while (next_permutation(d, d + 4));
}
void fmain() {
  ansVal = (1 << 30);
  for (int(i) = 0; (i) < (int)(4); (i)++) scanf("%d%d", x + i, y + i);
  set<int> ds;
  set<int> px, py;
  for (int(i) = 0; (i) < (int)(4); (i)++)
    for (int j = i + 1; j < 4; j++) {
      if (x[i] != x[j]) ds.insert(abs(x[i] - x[j]));
      if (y[i] != y[j]) ds.insert(abs(y[i] - y[j]));
    }
  for (int d : ds) {
    for (int(i) = 0; (i) < (int)(4); (i)++) {
      for (int j = -d; j <= d; j += d) {
        px.insert(x[i] + j);
        py.insert(y[i] + j);
      }
    }
  }
  for (int d : ds) {
    int id[4];
    for (int(i) = 0; (i) < (int)(4); (i)++) id[i] = i;
    do {
      int mxX = -(1 << 30), miX = (1 << 30), mxY = -(1 << 30), miY = (1 << 30);
      int tx[4], ty[4];
      tx[0] = x[id[0]];
      ty[0] = y[id[0]];
      tx[1] = x[id[1]] - d;
      ty[1] = y[id[1]];
      tx[2] = x[id[2]];
      ty[2] = y[id[2]] - d;
      tx[3] = x[id[3]] - d;
      ty[3] = y[id[3]] - d;
      for (int(i) = 0; (i) < (int)(4); (i)++) {
        mxX = max(mxX, tx[i]);
        miX = min(miX, tx[i]);
        mxY = max(mxY, ty[i]);
        miY = min(miY, ty[i]);
      }
      px.insert((mxX + miX) / 2);
      py.insert((mxY + miY) / 2);
    } while (next_permutation(id, id + 4));
  }
  for (int d : ds)
    for (int xx : px)
      for (int yy : py) ckeck(d, xx, yy);
  if (ansVal == (1 << 30))
    puts("-1");
  else {
    printf("%d\n", ansVal);
    for (int(i) = 0; (i) < (int)(4); (i)++)
      printf("%d %d\n", ans[i].first, ans[i].second);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) fmain();
  return 0;
}
