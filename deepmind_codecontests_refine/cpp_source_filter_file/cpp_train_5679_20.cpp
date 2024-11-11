#include <bits/stdc++.h>
using namespace std;
int N, M, Q, X, Y;
int MT[1001][1001];
int ans[200005];
vector<int> qidx[200005];
struct EDGE {
  int a, b;
} E[200005];
struct QUERY {
  int l, r, s, t, idx;
} QR[200005];
int main() {
  scanf("%d%d%d", &N, &M, &Q);
  for (int i = 1; i <= M; i++) scanf("%d%d", &E[i].a, &E[i].b);
  for (int i = 1; i <= Q; i++) {
    scanf("%d%d%d%d", &QR[i].l, &QR[i].r, &QR[i].s, &QR[i].t);
    qidx[QR[i].r].push_back(i);
  }
  for (int i = 1; i <= M; i++) {
    int &a = E[i].a, &b = E[i].b;
    for (int j = 1; j <= N; j++) {
      X = MT[a][j];
      Y = MT[b][a];
      if (MT[b][j] < X) MT[b][j] = X;
      if (MT[a][j] < Y) MT[a][j] = Y;
    }
    MT[b][a] = MT[a][b] = i;
    for (int &q : qidx[i]) {
      if (MT[QR[q].t][QR[q].s] >= QR[q].l) ans[q] = 1;
    }
  }
  for (int i = 1; i <= Q; i++) puts(ans[i] ? "Yes" : "No");
}
