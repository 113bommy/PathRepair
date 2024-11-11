#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
const int MAXLOG = 24;
long long int par[2 * MAXN][MAXLOG];
long long int h[2 * MAXN];
void get_par(int x) {
  for (int j = 1; j < MAXLOG; j++) {
    par[x][j] = par[par[x][j - 1]][j - 1];
  }
}
int LCA(int x, int y) {
  if (h[x] < h[y]) {
    swap(x, y);
  }
  for (int i = MAXLOG - 1; i >= 0; i--) {
    int cur = par[x][i];
    if (h[cur] >= h[y]) x = cur;
  }
  if (x == y) {
    return x;
  }
  for (int i = MAXLOG - 1; i >= 0; i--) {
    int cur1 = par[x][i];
    int cur2 = par[y][i];
    if (cur1 != cur2 && cur1 != -1 && cur2 != -1) {
      x = cur1;
      y = cur2;
    }
  }
  return par[x][0];
}
int main() {
  par[2][0] = 1;
  par[3][0] = 1;
  par[4][0] = 1;
  h[1] = 1;
  h[2] = 2;
  h[3] = 2;
  h[4] = 2;
  int ind1 = 2, ind2 = 4;
  int q;
  cin >> q;
  long long int tmp = 5;
  long long int answer = 2;
  for (int i = 0, v; i < q; i++) {
    scanf("%d", &v);
    par[tmp][0] = v;
    h[tmp] = h[v] + 1;
    tmp++;
    par[tmp][0] = v;
    h[tmp] = h[v] + 1;
    tmp++;
    get_par(tmp - 2);
    get_par(tmp - 1);
    int now1 = LCA(tmp - 2, ind1);
    int now2 = LCA(tmp - 2, ind2);
    int indd1 = 0, indd2 = 0;
    if (answer < (h[ind1] - h[now1] + h[tmp - 2] - h[now1])) {
      answer = h[ind1] - h[now1] + h[tmp - 2] - h[now1];
      indd1 = ind1;
      indd2 = tmp - 2;
    }
    if (answer < (h[ind2] - h[now2] + h[tmp - 2] - h[now2])) {
      answer = (h[ind2] - h[now2] + h[tmp - 2] - h[now2]);
      indd1 = tmp - 2;
      indd2 = ind2;
    }
    if (indd1 == 0 and indd2 == 0) {
      indd1 = ind1;
      indd2 = ind2;
    }
    ind1 = indd1;
    ind2 = indd2;
    printf("%I64d\n", answer);
  }
}
