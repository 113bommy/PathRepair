#include <bits/stdc++.h>
using namespace std;
char mat[2020][2020], jav[2020][2020], aux[2020][2020];
int n, a, b, mx[] = {0, 0, 1, -1, 1, 1, -1, -1},
             my[] = {1, -1, 0, 0, -1, 1, -1, 1};
long double sumx, sumy, qt;
vector<pair<int, long long> > vet;
void dfs(int i, int j) {
  if (i >= n || j >= n || i < 0 || j < 0 || jav[i][j]) return;
  jav[i][j] = 1;
  sumx += i;
  sumy += j;
  qt++;
  if (!mat[i][j])
    vet.push_back(make_pair(i, j));
  else
    for (int(k) = (0); (k) < (8); (k)++) dfs(i + mx[k], j + my[k]);
}
long double dist(long double va, long double vb, long double vc,
                 long double vd) {
  return hypot(va - vc, vb - vd);
}
int main() {
  scanf("%d", &n);
  for (int(i) = (0); (i) < (n); (i)++)
    for (int(j) = (0); (j) < (n); (j)++)
      scanf(" %c", &mat[i][j]), aux[i][j] = mat[i][j] - '0';
  for (int(i) = (1); (i) < (n - 1); (i)++)
    for (int(j) = (1); (j) < (n - 1); (j)++) {
      long double s = aux[i][j];
      for (int(k) = (0); (k) < (8); (k)++) s += aux[i + mx[k]][j + my[k]];
      s /= 9;
      if (s > 0.5)
        mat[i - 1][j - 1] = 1;
      else
        mat[i - 1][j - 1] = 0;
    }
  n -= 2;
  for (int(i) = (0); (i) < (n); (i)++)
    for (int(j) = (0); (j) < (n); (j)++)
      if (mat[i][j] && !jav[i][j]) {
        sumx = sumy = qt = 0;
        vet.clear();
        dfs(i, j);
        if (qt < 80) continue;
        sumx /= qt;
        sumy /= qt;
        long double dists = 0;
        for (int(k) = (0); (k) < (((int)(vet).size())); (k)++)
          dists += dist(sumx, sumy, vet[k].first, vet[k].second);
        dists /= ((int)(vet).size());
        long double desvio = 0;
        for (int(k) = (0); (k) < (((int)(vet).size())); (k)++)
          desvio += (dists - dist(sumx, sumy, vet[k].first, vet[k].second)) *
                    (dists - dist(sumx, sumy, vet[k].first, vet[k].second));
        desvio = sqrt(desvio) / ((int)(vet).size());
        if (desvio > 0.07)
          a++;
        else
          b++;
      }
  printf("%d %d\n", b, a);
}
