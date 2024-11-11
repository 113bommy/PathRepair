#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)2e5 + 10, L = 500;
vector<int> v, w[MAXN / L + 10];
int n, m, a[MAXN], b[MAXN / L + 10][L * 2], c[MAXN / L + 10][L * 2];
int pos(int first, int k) {
  if (k == -1) return first - 1;
  return first - 1 + m;
}
int Query(int l, int r, int second) {
  int pres = lower_bound((v).begin(), (v).end(), second) - v.begin(),
      Tohka = (int)1e9;
  for (int i = 0; i * L < n - m + 1 && i * L <= r; ++i) {
    int p =
        lower_bound((w[i]).begin(), (w[i]).end(), second) - w[i].begin() - 1;
    if (p < 0) {
      if ((i * L <= l && l <= i * L + L - 1) ||
          (i * L <= r && r <= i * L + L - 1))
        Tohka = min(Tohka, pres);
      continue;
    }
    if (l <= i * L && i + L - 1 <= r)
      Tohka = min(Tohka, pres + c[i][p]);
    else if ((i * L <= l && l <= i * L + L - 1) ||
             (i * L <= r && r <= i * L + L - 1)) {
      for (int j = i * L, s = pres; j < min(n - m + 1, (i + 1) * L); ++j) {
        for (int k = -1; k <= 1; k += 2) {
          int first = pos(j, k);
          if (!(0 <= first && first < n) || a[first] >= second) continue;
          s += k;
        }
        if (l <= j && j <= r) Tohka = min(Tohka, s);
      }
    }
    pres += b[i][p];
  }
  return Tohka;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < m - 1; ++i) v.push_back(a[i]);
  sort((v).begin(), (v).end());
  for (int i = 0; i * L < n - m + 1; ++i)
    for (int j = i * L; j < min(n - m + 1, (i + 1) * L); ++j)
      for (int k = -1; k <= 1; k += 2) {
        int first = pos(j, k);
        if (!(0 <= first && first < n)) continue;
        w[i].push_back(a[first]);
      }
  for (int i = 0; i * L < n - m + 1; ++i) {
    sort((w[i]).begin(), (w[i]).end());
    w[i].erase(unique((w[i]).begin(), (w[i]).end()), w[i].end());
    for (int p = 0; p < ((int)(w[i]).size()); ++p) {
      c[i][p] = (int)1e9;
      for (int j = i * L; j < min(n - m + 1, (i + 1) * L); ++j) {
        for (int k = -1; k <= 1; k += 2) {
          int first = pos(j, k);
          if (!(0 <= first && first < n) || a[first] > w[i][p]) continue;
          b[i][p] += k;
        }
        c[i][p] = min(c[i][p], b[i][p]);
      }
    }
  }
  int q, Tohka = 0;
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    int l, r, first;
    scanf("%d%d%d", &l, &r, &first);
    first ^= Tohka;
    printf("%d\n", Tohka = Query(l - 1, r - 1, first));
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
