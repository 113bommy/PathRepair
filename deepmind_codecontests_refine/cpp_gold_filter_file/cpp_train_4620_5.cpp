#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
const int base = 777777777;
struct change {
  int z;
  int x;
};
int n, m;
change a[MAXN];
int role[5][5];
long long ans[MAXN][5][5];
set<int> s;
int what[MAXN];
long long seg[MAXN * 10];
void ezaf(int l, int r, int z, int t, int k) {
  if (l == r) {
    seg[z] = k;
    return;
  }
  int v = (l + r) / 2;
  if (t <= v) {
    ezaf(l, v, 2 * z, t, k);
  } else {
    ezaf(v + 1, r, 2 * z + 1, t, k);
  }
  seg[z] = seg[2 * z] * seg[2 * z + 1];
  seg[z] %= base;
}
void remove(change r) {
  if (what[r.z] == 0) return;
  set<int>::iterator p = s.find(r.z);
  p--;
  int z1 = *p;
  p++;
  p++;
  int z2 = *p;
  p--;
  s.erase(p);
  ezaf(0, n, 1, z1, 1);
  ezaf(0, n, 1, r.z, 1);
  ezaf(0, n, 1, z1, ans[z2 - z1 - 1][what[z1]][what[z2]]);
  what[r.z] = 0;
}
void add(change r) {
  if (r.x == 0) return;
  s.insert(r.z);
  what[r.z] = r.x;
  set<int>::iterator p = s.find(r.z);
  p--;
  int z1 = *p;
  p++;
  p++;
  int z2 = *p;
  p--;
  ezaf(0, n, 1, z1, 1);
  ezaf(0, n, 1, z1, ans[r.z - z1 - 1][what[z1]][what[r.z]]);
  ezaf(0, n, 1, r.z, ans[z2 - r.z - 1][what[r.z]][what[z2]]);
}
void init() {
  for (int i = 1; i <= 3; i++) role[i][4] = role[4][i] = 1;
  for (int i = 0; i <= n; i++)
    for (int j = 1; j <= 4; j++)
      for (int k = 1; k <= 4; k++) {
        if (i == 0)
          ans[i][j][k] = role[j][k];
        else
          for (int h = 1; h <= 3; h++)
            if (role[j][h]) ans[i][j][k] += ans[i - 1][h][k];
        ans[i][j][k] %= base;
      }
  for (int i = 1; i <= 4 * n + 100; i++) seg[i] = 1;
  what[0] = what[n + 1] = 4;
  s.insert(0);
  s.insert(n + 1);
  ezaf(0, n, 1, 0, ans[n][4][4]);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) cin >> role[i][j];
  init();
  for (int i = 1; i <= m; i++) {
    cin >> a[i].z >> a[i].x;
    remove(a[i]);
    add(a[i]);
    cout << seg[1] << endl;
  }
}
