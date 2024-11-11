#include <bits/stdc++.h>
using namespace std;
int a[110][310];
int b[110][110];
int c[10010];
int reach[110];
bool used[100010];
int getPos(int t, int i) {
  int j = a[i][0] - 1;
  int pos = 0;
  if (t >= a[i][2 + 3 * j]) return a[i][3 + 3 * j];
  while (t < a[i][2 + 3 * j]) j--;
  if (j < 0)
    pos = a[i][1] * t;
  else
    pos = a[i][3 + 3 * j] + a[i][1 + 3 * (j + 1)] * (t - a[i][2 + 3 * j]);
  return pos;
}
int cmp(const void *p, const void *q) { return *(int *)p - *(int *)q; }
int main() {
  int n, s;
  cin >> n >> s;
  queue<int> q;
  int m = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i][0];
    int t = 0;
    int p = 0;
    for (int j = 0; j < a[i][0]; j++) {
      int l, v;
      cin >> v >> l;
      t += l;
      p += v * l;
      a[i][1 + 3 * j] = v;
      a[i][2 + 3 * j] = t;
      a[i][3 + 3 * j] = p;
      if (!used[t]) {
        c[m++] = t;
        used[t] = true;
      }
    }
  }
  qsort(c, m, sizeof(int), cmp);
  int res = 0;
  for (int k = 0; k < m; k++) {
    int t = c[k];
    for (int i = 0; i < n; i++) {
      if (reach[i] && reach[i] < t) continue;
      int pi = getPos(t, i);
      if (pi == s) reach[i] = t;
      for (int j = i + 1; j < n; j++) {
        if (reach[j] && reach[j] < t) continue;
        int pj = getPos(t, j);
        if (pi == s) reach[j] = t;
        if (pi < pj) {
          if (b[i][j] >= 1) res++;
          b[i][j] = -2;
          b[j][i] = 2;
        } else if (pi > pj) {
          if (b[i][j] <= -1) res++;
          b[i][j] = 2;
          b[j][i] = -2;
        } else {
          if (b[i][j] > 1 || b[i][j] < -1) {
            b[i][j] /= 2;
            b[j][i] /= 2;
          }
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}
