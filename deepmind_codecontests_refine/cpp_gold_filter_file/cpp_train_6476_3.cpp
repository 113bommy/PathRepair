#include <bits/stdc++.h>
using namespace std;
int a[400100], acum[400100], val[400100];
pair<int, int> qt[400100];
int main() {
  int n;
  while (scanf("%d", &n) > 0) {
    map<int, int> id;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      id[a[i]] = 0;
    }
    int v = 0;
    for (map<int, int>::iterator it = id.begin(); it != id.end(); it++) {
      id[it->first] = ++v;
      val[v] = it->first;
      qt[v] = make_pair(0, v);
    }
    for (int i = 1; i <= n; i++) {
      qt[id[a[i]]].first++;
    }
    sort(qt + 1, qt + 1 + v);
    acum[0] = 0;
    for (int i = 1; i <= v; i++) {
      acum[i] = acum[i - 1] + qt[i].first;
    }
    int x = 0, best_q;
    for (int q = 1; q <= n; q++) {
      int lo = 1, up = v, i = 0;
      while (lo <= up) {
        int mid = (lo + up) >> 1;
        if (qt[mid].first < q) {
          i = mid;
          lo = mid + 1;
        } else {
          up = mid - 1;
        }
      }
      int X = acum[i] + (v - i) * q;
      int p = X / q;
      if (p >= q) {
        X = p * q;
        if (X > x) {
          x = X;
          best_q = q;
        }
      }
    }
    printf("%d\n", x);
    int q = best_q;
    int p = x / q;
    printf("%d %d\n", p, q);
    vector<vector<int> > grid(p, vector<int>(q, 0));
    int r = 0, c = 0, i = v;
    while (x) {
      for (int j = 0; j < min(qt[i].first, q) and x; j++) {
        grid[r][c] = val[qt[i].second];
        r = (r + 1) % p;
        c = (c + 1) % q;
        if (grid[r][c]) r = (r + 1) % p;
        x--;
      }
      i--;
    }
    for (int i = 0; i < p; i++) {
      for (int j = 0; j < q; j++) {
        if (j) printf(" ");
        printf("%d", grid[i][j]);
      }
      printf("\n");
    }
  }
}
