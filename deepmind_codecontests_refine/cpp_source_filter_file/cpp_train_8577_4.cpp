#include <bits/stdc++.h>
using namespace std;
const int Maxn = 3010, Maxm = 100010;
typedef int IArr[Maxn][Maxn];
struct Point {
  int x, y, det, len;
  void add(int k) {
    if (k) x++, y++;
    det = x - y;
  }
};
struct Rec {
  int x1, y1, x2, y2;
  Rec(Point a, Point b) {
    x1 = a.x;
    y1 = a.y;
    x2 = b.x;
    y2 = b.y;
  }
  Rec() {}
  bool inRec(int nx1, int ny1, int nx2, int ny2) {
    if (nx1 <= x1 + 1 && x2 <= nx2)
      if (ny1 <= y1 + 1 && y2 <= ny2) return 1;
    return 0;
  }
};
Rec Re[Maxm];
IArr ct, U, D, L, R, BX, BY, vis;
Point S[Maxn], LB[Maxm], RT[Maxm];
int n, i, j, k, t, p;
bool cmp(Point a, Point b) {
  if (a.det != b.det) return a.det < b.det;
  return a.x < b.x;
}
void pt(int x1, int y1, int x2, int y2, int id) {
  int SV[Maxn], ans = 0;
  for (int i = 1; i <= n; i++)
    if (Re[i].inRec(x1, y1, x2, y2)) SV[++ans] = i;
  cout << "YES " << ans << endl;
  for (int i = 1; i <= ans; i++) cout << SV[i] << ' ';
  cout << endl;
  exit(0);
}
int getsum(int x1, int y1, int x2, int y2) {
  return ct[x2][y2] - ct[x1 - 1][y2] - ct[x2][y1 - 1] + ct[x1 - 1][y1 - 1];
}
void check(int id) {
  for (p = 1; p <= t && S[p].x <= RT[id].x; p++) {
    if (S[p].x + S[p].len - 1 < RT[id].x) continue;
    if (RT[id].x - RT[id].len + 1 > S[p].x) continue;
    int sum = getsum(S[p].x, S[p].y, RT[id].x, RT[id].y);
    int l = RT[id].x - S[p].x + 1;
    if (l * l == sum) pt(S[p].x, S[p].y, RT[id].x, RT[id].y, id);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> LB[i].x >> LB[i].y >> RT[i].x >> RT[i].y;
    Re[i] = Rec(LB[i], RT[i]);
    LB[i].add(1);
    RT[i].add(0);
    for (int x = LB[i].x; x <= RT[i].x; x++)
      for (int y = LB[i].y; y <= RT[i].y; y++) ct[x][y] = 1, vis[x][y] = i;
    for (int y = Re[i].y1 + 1; y <= Re[i].y2; y++)
      U[Re[i].x1][y] = U[Re[i].x2][y] = D[Re[i].x1][y] = D[Re[i].x2][y] = 1;
    for (int x = Re[i].x1 + 1; x <= Re[i].x2; x++)
      L[x][Re[i].y1] = L[x][Re[i].y2] = R[x][Re[i].y1] = R[x][Re[i].y2] = 1;
  }
  for (int i = 1; i <= 3000; i++)
    for (int j = 1; j <= 3000; j++)
      ct[i][j] += ct[i - 1][j] + ct[i][j - 1] - ct[i - 1][j - 1];
  for (int i = 3000; i >= 0; i--)
    for (int j = 0; j <= 3000; j++) R[i][j] = R[i][j] ? R[i + 1][j] + 1 : 0;
  for (int i = 0; i <= 3000; i++)
    for (int j = 3000; j >= 0; j--) U[i][j] = U[i][j] ? U[i][j + 1] + 1 : 0;
  for (int i = 1; i <= 3000; i++)
    for (int j = 1; j <= 3000; j++) L[i][j] = L[i][j] ? L[i - 1][j] + 1 : 0;
  for (int i = 1; i <= 3000; i++)
    for (int j = 1; j <= 3000; j++) D[i][j] = D[i][j] ? D[i][j - 1] + 1 : 0;
  for (int i = 1; i <= n; i++) {
    int x = Re[i].x1, y = Re[i].y1;
    LB[i].len = min(R[x + 1][y], U[x][y + 1]);
    x = Re[i].x2, y = Re[i].y2;
    RT[i].len = min(L[x][y], D[x][y]);
  }
  sort(LB + 1, LB + n + 1, cmp);
  sort(RT + 1, RT + n + 1, cmp);
  for (i = j = 1; i <= n; t = 0, i = k) {
    while (j <= n && LB[j].det < RT[i].det) j++;
    for (; j <= n && LB[j].det == RT[i].det; j++) S[++t] = LB[j];
    check(i);
    for (k = i + 1; k <= n && RT[k].det == RT[i].det; k++) check(k);
  }
  cout << "NO\n";
}
