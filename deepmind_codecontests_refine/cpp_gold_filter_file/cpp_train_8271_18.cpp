#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n, p;
struct LIST {
  int t, h, c;
} a[5000];
int q;
vector<int> b[30000];
vector<int> c[30000];
int query[30000][2];
int d[2][4005][4005];
int dat[2][30000];
int dab[30000];
int main() {
  int i, j, k;
  cin >> n >> p;
  for (i = 0; i < n; i++) {
    scanf("%d%d%d", &a[i].c, &a[i].h, &a[i].t);
    b[a[i].t].push_back(i);
  }
  cin >> q;
  for (i = 0; i < q; i++)
    scanf("%d%d", &query[i][0], &query[i][1]), c[query[i][0]].push_back(i);
  for (i = 1; i <= 20000; i += p) {
    fill(d[0][0], d[0][0] + 4005, 0);
    fill(d[1][0], d[1][0] + 4005, 0);
    int dati = 1;
    for (j = i; j < i + p && j <= 20000; j++) {
      for (auto e : b[j]) {
        for (k = 0; k < 4005; k++) d[0][dati][k] = d[0][dati - 1][k];
        for (k = 0; k < 4005; k++) {
          if (k + a[e].c >= 4005) break;
          d[0][dati][k + a[e].c] =
              max(d[0][dati][k + a[e].c], d[0][dati - 1][k] + a[e].h);
        }
        dati++;
      }
      dat[0][j] = dati - 1;
    }
    dati = 1;
    for (j = i - 1; j > i - p && j >= 0; j--) {
      for (auto e : b[j]) {
        for (k = 0; k < 4005; k++) d[1][dati][k] = d[1][dati - 1][k];
        for (k = 0; k < 4005; k++) {
          if (k + a[e].c >= 4005) break;
          d[1][dati][k + a[e].c] =
              max(d[1][dati][k + a[e].c], d[1][dati - 1][k] + a[e].h);
        }
        dati++;
      }
      dat[1][j] = dati - 1;
    }
    for (j = i; j < i + p; j++) {
      for (auto e : c[j]) {
        int ma = 0;
        for (k = 0; k <= query[e][1]; k++) {
          ma = max(ma, (j - p + 1 >= 0 ? d[1][dat[1][j - p + 1]][k] : 0) +
                           d[0][dat[0][j]][query[e][1] - k]);
        }
        dab[e] = ma;
      }
    }
  }
  for (i = 0; i < q; i++) printf("%d\n", dab[i]);
  return 0;
}
