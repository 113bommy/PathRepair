#include <bits/stdc++.h>
using namespace std;
const int C = 210001;
vector<vector<int> > gr(C);
vector<vector<long long> > E(C);
int ij[C], a, b, n, m, ls[C], k, v[C];
long long w, summ = 0;
long long h[2 * C];
int h2[2 * C], h3[2 * C], ih = 1;
void exch(int a, int b) {
  h[a] += h[b], h[b] = h[a] - h[b], h[a] -= h[b];
  h2[a] += h2[b], h2[b] = h2[a] - h2[b], h2[a] -= h2[b];
  h3[a] += h3[b], h3[b] = h3[a] - h3[b], h3[a] -= h3[b];
}
void pop() {
  h[1] = h[ih - 1], h2[1] = h2[ih - 1], h3[1] = h3[ih - 1], ih--;
  int j = 1;
  while (j < ih) {
    if (j * 2 < ih && h[j * 2] < h[j] &&
        (h[j * 2 + 1] >= h[j * 2] || j * 2 + 1 >= ih))
      exch(j, j * 2), j = j * 2;
    else if (j * 2 + 1 < ih && h[j * 2 + 1] < h[j] && h[j * 2 + 1] < h[j * 2])
      exch(j, j * 2 + 1), j = j * 2 + 1;
    else
      break;
  }
}
void push(long long a, int v, int pr) {
  h[ih] = a, h2[ih] = v, h3[ih] = pr, ih++;
  int j = ih - 1;
  while (j > 1) {
    if (h[j / 2] > h[j])
      exch(j, j / 2), j /= 2;
    else
      break;
  }
}
bool check[C];
long long dst[C];
void full_dijkstra(vector<vector<int> > &tab, vector<vector<long long> > &e,
                   int ij[]) {
  int j = 0, y, z;
  long long x;
  for (int i = 0; i < k; i++) push(0, ls[i], ls[i]);
  while (ih > 1) {
    x = h[1], y = h2[1], z = h3[1];
    pop();
    if (check[y] == 1) continue;
    check[y] = 1, dst[y] = x, v[y] = z;
    while (j < ij[y]) {
      if (check[tab[y][j]] == 0) push(x + e[y][j], tab[y][j], v[y]);
      j++;
    }
    j = 0;
  }
}
long long pom[C];
int pom2[C], pom3[C];
void Sebasort(long long tab[], int tab2[], int tab3[], int l, int r) {
  int lim = 2, limi = l + 1, limj = l + 2, j = limi, i = l, k = l;
  while (lim / 2 <= r - l + 1) {
    while (i <= r) {
      if (limj > r) limj = r + 1;
      if ((tab[j] < tab[i] && j < limj) || i >= limi)
        pom[k] = tab[j], pom2[k] = tab2[j], pom3[k] = tab3[j], j++;
      else
        pom[k] = tab[i], pom2[k] = tab2[i], pom3[k] = tab3[i], i++;
      k++;
      if (i == limi && j == limj) limi += lim, limj += lim, i = j, j = limi;
    }
    for (i = l; i <= r; i++)
      tab[i] = pom[i], tab2[i] = pom2[i], tab3[i] = pom3[i];
    lim *= 2, limi = l + lim / 2, limj = l + lim, j = limi, i = k = l;
  }
}
int pr[C], ran[C];
void make_set(int x) { pr[x] = x, ran[x] = 0; }
int find_set(int x) {
  if (x != pr[x]) pr[x] = find_set(pr[x]);
  return pr[x];
}
void find_union(int a, int b) {
  int x = find_set(a), y = find_set(b);
  if (ran[x] > ran[y])
    pr[y] = x;
  else
    pr[x] = y;
  if (ran[x] == ran[y]) ran[y]++;
}
int f1[C], f2[C], im;
long long f3[C];
void create_mst(int f1[], int f2[], long long f3[], int k, int m) {
  int i, a, b;
  for (i = 0; i < k; i++) make_set(ls[i]);
  Sebasort(f3, f2, f1, 0, im - 1);
  for (i = 0; i < im; i++) {
    a = find_set(f1[i]), b = find_set(f2[i]);
    if (a != b) {
      find_union(a, b);
      a = f1[i], b = f2[i];
      summ += f3[i];
      ij[a]++, ij[b]++;
    }
  }
}
void add(int a, int b, long long e) {
  f1[im] = a, f2[im] = b, f3[im] = e, im++;
}
int main() {
  int i, j;
  scanf("%d %d", &n, &m);
  for (int z = 0; z < m; z++)
    scanf("%d %d %I64d", &a, &b, &w), gr[a].push_back(b), gr[b].push_back(a),
        E[a].push_back(w), E[b].push_back(w), ij[a]++, ij[b]++;
  scanf("%d", &k);
  for (i = 0; i < k; i++) scanf("%d", &a), ls[i] = a;
  full_dijkstra(gr, E, ij);
  for (i = 1; i <= n; i++) {
    for (j = 0; j < ij[i]; j++) {
      if (v[i] != v[gr[i][j]])
        add(v[gr[i][j]], v[i], E[i][j] + dst[i] + dst[gr[i][j]]);
    }
  }
  create_mst(f1, f2, f3, k, im);
  printf("%I64d", summ + dst[1]);
  return 0;
}
