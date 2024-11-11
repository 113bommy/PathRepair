#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int MAGIC = 320;
int n, k, q, RSize = 0;
int t[N], a[N];
int pos[4][N], C[4][N];
long long totAns = 0;
long long S[N], R[N], ans[N];
struct Query {
  int l, r, i;
  Query() {}
  Query(int l, int r) : l(l), r(r) {}
  bool operator<(const Query &that) const {
    int x = l / MAGIC, y = that.l / MAGIC;
    if (x != y) return x < y;
    return r < that.r;
  }
  friend void Read(Query &A) { scanf("%d%d", &A.l, &A.r); }
} Q[N];
void Compress() {
  for (int i = 1; i <= n; ++i) {
    R[++RSize] = S[i];
    R[++RSize] = S[i] - k;
    R[++RSize] = S[i - 1] + k;
    R[++RSize] = S[i - 1];
  }
  sort(R + 1, R + RSize + 1);
  RSize = unique(R + 1, R + RSize + 1) - R - 1;
}
int Pos(long long v) { return lower_bound(R + 1, R + RSize + 1, v) - R; }
void Update(int i, int v) {
  C[0][pos[0][i]] += v;
  C[1][pos[1][i]] += v;
  C[2][pos[2][i]] += v;
  C[3][pos[3][i]] += v;
}
void InsertRight(int i) {
  Update(i, +1);
  int p = pos[1][i];
  totAns += C[3][p];
}
void InsertLeft(int i) {
  Update(i, +1);
  int p = pos[2][i];
  totAns += C[0][p];
}
void RemoveLeft(int i) {
  int p = pos[2][i];
  totAns -= C[0][p];
  Update(i, -1);
}
void RemoveRight(int i) {
  int p = pos[1][i];
  totAns -= C[3][p];
  Update(i, -1);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &t[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) S[i] = S[i - 1] + (t[i] == 1 ? +a[i] : -a[i]);
  Compress();
  for (int i = 1; i <= n; ++i) {
    pos[0][i] = Pos(S[i]);
    pos[1][i] = Pos(S[i] - k);
    pos[2][i] = Pos(S[i - 1] + k);
    pos[3][i] = Pos(S[i - 1]);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) Read(Q[i]), Q[i].i = i;
  sort(Q + 1, Q + q + 1);
  int cL = 1, cR = 0;
  for (int i = 1; i <= q; ++i) {
    int l = Q[i].l, r = Q[i].r;
    while (cR < r) InsertRight(++cR);
    while (cR > r) RemoveRight(cR--);
    while (cL < l) RemoveLeft(cL++);
    while (cL > l) InsertLeft(--cL);
    ans[Q[i].i] = totAns;
  }
  for (int i = 1; i <= q; ++i) printf("%I64d\n", ans[i]);
  return 0;
}
