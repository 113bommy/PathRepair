#include <bits/stdc++.h>
long long incs1[52];
long long incs2[52];
long long edge[52][4];
int k, x, n, m;
void outputc(int id) {
  if (id == 0) printf("A");
  if (id == 1) printf("B");
  if (id == 2) printf("C");
}
int main() {
  incs1[1] = 1;
  incs2[1] = 0;
  incs1[2] = 0;
  incs2[2] = 1;
  int topa = 0;
  int enda = 0;
  int topb = 1;
  int endb = 1;
  for (int i = 0; i < 4; i++) {
    edge[1][i] = 0;
    edge[2][i] = 0;
  }
  for (int i = 3; i < 51; i++) {
    for (int j = 0; j < 4; j++) edge[i][j] = 0;
    edge[i][enda * 2 + topb]++;
    for (int j = 0; j < 4; j++) edge[i][j] += edge[i - 2][j] + edge[i - 1][j];
    int topc = topa;
    int endc = endb;
    topa = topb;
    enda = endb;
    topb = topc;
    endb = endc;
    incs1[i] = incs1[i - 2] + incs1[i - 1];
    incs2[i] = incs2[i - 2] + incs2[i - 1];
  }
  scanf("%d%d%d%d", &k, &x, &n, &m);
  for (int i1 = 0; i1 < 3; i1++) {
    for (int i2 = 0; i2 < 3; i2++) {
      if (n > 1 || i1 == i2) {
        int s1maxln = n;
        if (i1 != 0) s1maxln--;
        if (i2 != 2) s1maxln--;
        int s1max = s1maxln / 2;
        if (s1max < 0) s1max = 0;
        int s1min = 0;
        if (n == 2 && s1maxln == 2) s1min = 1;
        for (int j1 = 0; j1 < 3; j1++) {
          for (int j2 = 0; j2 < 3; j2++) {
            if (m > 1 || j1 == j2) {
              int s2maxln = m;
              if (j1 != 0) s2maxln--;
              if (j2 != 2) s2maxln--;
              int s2max = s2maxln / 2;
              if (s2max < 0) s2max = 0;
              int s2min = 0;
              if (m == 2 && s2maxln == 2) s2min = 1;
              for (int k1 = s1min; k1 <= s1max; k1++) {
                for (int k2 = s2min; k2 <= s2max; k2++) {
                  long long kx = 0;
                  kx += incs1[k] * k1;
                  kx += incs2[k] * k2;
                  if (kx <= x) {
                    if (i1 == 2 && i2 == 0) kx += edge[k][0];
                    if (i1 == 2 && j2 == 0) kx += edge[k][1];
                    if (j1 == 2 && i2 == 0) kx += edge[k][2];
                    if (j1 == 2 && j2 == 0) kx += edge[k][3];
                    if (kx == x) {
                      int called = 0;
                      if (i1 != 0) {
                        outputc(i1);
                        called++;
                      }
                      for (int t = 0; t < k1; t++) {
                        printf("AC");
                        called += 2;
                      }
                      if (i1 == 0 && called == 0) {
                        printf("A");
                        called++;
                      }
                      while (called < n - 1) {
                        printf("B");
                        called++;
                      }
                      if (called < n) outputc(i2);
                      printf("\n");
                      called = 0;
                      if (j1 != 0) {
                        outputc(j1);
                        called++;
                      }
                      for (int t = 0; t < k2; t++) {
                        printf("AC");
                        called += 2;
                      }
                      if (j1 == 0 && called == 0) {
                        printf("A");
                        called++;
                      }
                      while (called < m - 1) {
                        printf("B");
                        called++;
                      }
                      if (called < m) outputc(j2);
                      printf("\n");
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  printf("Happy new year!\n");
  return 0;
}
