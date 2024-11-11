#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> a(k);
  for (int i = 0; i < (k); ++i) {
    scanf("%d", &(a[i]));
    a[i]--;
  }
  sort((a).begin(), (a).end());
  vector<int> r(1 << (n - 1));
  for (int i = 0; i < (k); ++i) {
    r[a[i] / 2]++;
  }
  int res = 1;
  for (auto i : r) {
    if (i) res++;
  }
  vector<vector<int> > ra(1 << (n - 2), vector<int>(4, -4 * (1 << n)));
  for (int i = 0; i < (((int)(ra).size())); ++i) {
    if (max(r[2 * i], r[2 * i + 1]) >= 2) {
      ra[i][3] = 0;
    } else {
      if (min(r[2 * i], r[2 * i + 1])) {
        ra[i][1] = 0;
        ra[i][2] = 0;
        ra[i][3] = 0;
      } else {
        if (max(r[2 * i], r[2 * i + 1])) {
          ra[i][1] = 0;
          ra[i][2] = 0;
        } else {
          ra[i][0] = 0;
        }
      }
    }
  }
  int kk = n - 3;
  int lim = -4 * (1 << n);
  while (kk >= 0) {
    vector<vector<int> > nra(1 << kk, vector<int>(4, lim));
    for (int i = 0; i < (((int)(nra).size())); ++i) {
      nra[i][0] = max(lim, ra[2 * i][0] + ra[2 * i + 1][0]);
      nra[i][1] = max(max(max(lim, ra[2 * i][1] + ra[2 * i + 1][1] + 2),
                          ra[2 * i][1] + ra[2 * i + 1][0] + 1),
                      ra[2 * i][0] + ra[2 * i + 1][1] + 1);
      nra[i][2] = max(max(max(lim, ra[2 * i][2] + ra[2 * i + 1][2] + 4),
                          ra[2 * i][2] + ra[2 * i + 1][0] + 2),
                      ra[2 * i][0] + ra[2 * i + 1][2] + 2);
      nra[i][3] = max(max(max(lim, ra[2 * i][3] + ra[2 * i + 1][0] + 3),
                          ra[2 * i][3] + ra[2 * i + 1][1] + 4),
                      ra[2 * i][3] + ra[2 * i + 1][2] + 5);
      nra[i][3] = max(max(max(nra[i][3], ra[2 * i][0] + ra[2 * i + 1][3] + 3),
                          ra[2 * i][1] + ra[2 * i + 1][3] + 4),
                      ra[2 * i][2] + ra[2 * i + 1][3] + 5);
      nra[i][3] = max(max(max(nra[i][3], ra[2 * i][3] + ra[2 * i + 1][3] + 6),
                          ra[2 * i][1] + ra[2 * i + 1][2] + 3),
                      ra[2 * i][2] + ra[2 * i + 1][1] + 3);
    }
    ra = nra;
    kk--;
  }
  int madd = -4;
  for (int i = 0; i < (4); ++i) {
    madd = max(madd, ra[0][i] + i);
  }
  printf("%d\n", res + madd);
}
