#include <bits/stdc++.h>
using namespace std;
struct node {
  int son[2], sum;
};
struct seg_tre {
  node tr[2000010];
  int cnt;
  int Insert(int p, int l, int r, int x) {
    int k = ++cnt;
    tr[k] = tr[p];
    tr[k].sum++;
    if (l == r - 1) return k;
    if (x + 1 <= ((l + r) >> 1))
      tr[k].son[0] = Insert(tr[p].son[0], l, ((l + r) >> 1), x);
    else
      tr[k].son[1] = Insert(tr[p].son[1], ((l + r) >> 1), r, x);
    return k;
  }
  int Getsum(int p, int l, int r, int x) {
    if (p == 0) return 0;
    if (r == x + 1) return tr[p].sum;
    if (x + 1 <= ((l + r) >> 1))
      return Getsum(tr[p].son[0], l, ((l + r) >> 1), x);
    return tr[tr[p].son[0]].sum + Getsum(tr[p].son[1], ((l + r) >> 1), r, x);
  }
} T;
int n, a[9], X[100010], Y[100010], tx, ty, b[9], A[3][3], Sx[100010],
    Sy[100010], root[100010];
pair<int, int> p[100010];
vector<int> V[100010];
void read(int &x) {
  char ch = getchar();
  int mark = 1;
  for (; ch != '-' && (ch < '0' || ch > '9'); ch = getchar())
    ;
  if (ch == '-') mark = -1, ch = getchar();
  for (x = 0; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - 48;
  x *= mark;
}
bool check(int x1, int x2, int y1, int y2) {
  int s = A[2][0];
  if (T.Getsum(root[x1], 1, ty + 1, y1) != s) return 0;
  s += A[2][1];
  if (T.Getsum(root[x2], 1, ty + 1, y1) != s) return 0;
  s = A[2][0] + A[1][0];
  if (T.Getsum(root[x1], 1, ty + 1, y2) != s) return 0;
  s += A[2][1] + A[1][1];
  if (T.Getsum(root[x2], 1, ty + 1, y2) != s) return 0;
  return 1;
}
int main() {
  read(n);
  for (int i = 1; i <= n; i++) {
    read(p[i].first);
    read(p[i].second);
    X[i] = p[i].first, Y[i] = p[i].second;
  }
  for (int i = 0; i < 9; i++) read(a[i]);
  sort(X + 1, X + n + 1);
  tx = unique(X + 1, X + n + 1) - (X + 1);
  sort(Y + 1, Y + n + 1);
  ty = unique(Y + 1, Y + n + 1) - (Y + 1);
  for (int i = 1; i <= n; i++) {
    p[i].first = lower_bound(X + 1, X + tx + 1, p[i].first) - X;
    Sx[p[i].first]++;
    p[i].second = lower_bound(Y + 1, Y + ty + 1, p[i].second) - Y;
    Sy[p[i].second]++;
    V[p[i].first].push_back(p[i].second);
  }
  for (int i = 1; i <= tx; i++) {
    root[i] = root[i - 1];
    for (int j = 0; j < V[i].size(); j++)
      root[i] = T.Insert(root[i], 1, ty + 1, V[i][j]);
  }
  for (int i = 1; i <= tx; i++) Sx[i] += Sx[i - 1];
  for (int i = 1; i <= ty; i++) Sy[i] += Sy[i - 1];
  for (int i = 0; i < 9; i++) b[i] = i;
  do {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) A[i][j] = a[b[i * 3 + j]];
    int s1 = A[0][0] + A[1][0] + A[2][0], s2 = s1 + A[0][1] + A[1][1] + A[2][1];
    int x1 = lower_bound(Sx + 1, Sx + tx + 1, s1) - Sx,
        x2 = lower_bound(Sx + 1, Sx + tx + 1, s2) - Sx;
    if (Sx[x1] != s1 || Sx[x2] != s2) continue;
    s1 = A[2][0] + A[2][1] + A[2][2];
    s2 = s1 + A[1][0] + A[1][1] + A[1][2];
    int y1 = lower_bound(Sy + 1, Sy + ty + 1, s1) - Sy,
        y2 = lower_bound(Sy + 1, Sy + ty + 1, s2) - Sy;
    if (Sy[y1] != s1 || Sy[y2] != s2) continue;
    if (!check(x1, x2, y1, y2)) continue;
    printf("%.1lf %.1lf\n%.1lf %.1lf\n", 0.5 + X[x1], 0.5 + X[x2], 0.5 + Y[y1],
           0.5 + Y[y2]);
    return 0;
  } while (next_permutation(b, b + 9));
  printf("-1\n");
  return 0;
}
