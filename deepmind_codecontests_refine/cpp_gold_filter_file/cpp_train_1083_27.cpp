#include <bits/stdc++.h>
using namespace std;
static const int Nmax = 2001;
static const int Mmax = 2001;
static const int Smax = 100001;
static const int Kmax = 10;
static int n, m, k, s;
static int Amin[Kmax][Nmax];
static int Amax[Kmax][Nmax];
static void readData() {
  scanf("%i%i%i%i", &n, &m, &k, &s);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int nota;
      scanf("%i", &nota);
      if (Amin[nota][i] == 0) {
        Amin[nota][i] = j;
      }
      Amax[nota][i] = j;
    }
  }
}
static int findDist(int k1, int k2) {
  int maxDist = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int vert = abs(j - i);
      int gor1 = -1;
      if (Amax[k1][i] > 0 && Amin[k2][j] > 0) {
        gor1 = abs(Amax[k1][i] - Amin[k2][j]);
      }
      int gor2 = -1;
      if (Amin[k1][i] > 0 && Amax[k2][j] > 0) {
        gor2 = abs(Amin[k1][i] - Amax[k2][j]);
      }
      int gor = max(gor1, gor2);
      if (vert + gor > maxDist) {
        maxDist = vert + gor;
      }
    }
  }
  return maxDist;
}
int main() {
  readData();
  int dist[Kmax][Kmax];
  for (int i = 1; i <= k; i++) {
    for (int j = i; j <= k; j++) {
      int d = findDist(i, j);
      dist[i][j] = dist[j][i] = d;
    }
  }
  int maxDist = 0;
  int prevNota;
  scanf("%i", &prevNota);
  for (int i = 1; i < s; i++) {
    int nota;
    scanf("%i", &nota);
    if (dist[prevNota][nota] > maxDist) {
      maxDist = dist[prevNota][nota];
    }
    prevNota = nota;
  }
  printf("%i\n", maxDist);
  return 0;
}
