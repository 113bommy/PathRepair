#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int n, m, M;
int zhan[1000005], top;
int vis[1000005], jl[1000005], qwq[1000005];
int P[1000005], bh[5000005];
struct node {
  double x, y;
} A[5000005], B[5000005];
node operator+(node aa, node bb) { return (node){aa.x + bb.x, aa.y + bb.y}; }
node operator-(node aa, node bb) { return (node){aa.x - bb.x, aa.y - bb.y}; }
node operator*(node aa, node bb) {
  return (node){aa.x * bb.x - aa.y * bb.y, aa.x * bb.y + aa.y * bb.x};
}
void fft(node *a, int ff) {
  for (int i = 0; i < M; ++i)
    if (bh[i] < i) swap(a[i], a[bh[i]]);
  for (int i = 1; i < M; i <<= 1) {
    node yuan = (node){cos(pi / i), ff * sin(pi / i)};
    for (int j = 0; j < M; j += (i << 1)) {
      node kk = (node){1., 0.};
      for (int k = 0; k < i; kk = kk * yuan, ++k) {
        node aa = a[j + k], bb = a[j + k + i] * kk;
        a[j + k] = aa + bb;
        a[j + k + i] = aa - bb;
      }
    }
  }
  return;
}
int main() {
  scanf("%d%d", &n, &m);
  M = 1;
  while (M < (m << 1)) M <<= 1;
  for (int i = 1; i < M; ++i) bh[i] = (bh[i >> 1] >> 1) | (i & 1 ? M >> 1 : 0);
  for (int i = 1; i <= n; ++i) scanf("%d", &P[i]), vis[P[i]] = 1, jl[P[i]] = 1;
  A[0].x = 1;
  B[0].x = 1;
  jl[0] = 1;
  for (int i = 1; i <= n; ++i) {
    A[P[i]].x = 1;
    B[P[i]].x = 1;
    if (!qwq[P[i]])
      for (int j = 1; j * P[i] <= m; ++j) {
        if (!vis[j * P[i]]) {
          puts("NO");
          return 0;
        }
        qwq[j * P[i]] = 1;
      }
  }
  fft(A, 1);
  fft(B, 1);
  for (int i = 0; i < M; ++i) A[i] = A[i] * B[i];
  fft(A, -1);
  for (int i = 0; i <= m; ++i) {
    A[i].x = (int)(A[i].x + 0.5) / M;
    if (!A[i].x) continue;
    if (!jl[i]) {
      puts("NO");
      return 0;
    }
    if (A[i].x == 2) zhan[++top] = i;
  }
  puts("YES");
  printf("%d\n", top);
  for (int i = 1; i <= top; ++i) printf("%d ", zhan[i]);
  return 0;
}
