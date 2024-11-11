#include <bits/stdc++.h>
using namespace std;
int n, k;
char f[502][502];
int grp[502][502];
int qtd[502 * 502];
int cc[502 * 502];
int qtddot[502][502];
int qtddot2[502][502];
int dirlen = 4;
int dirx[] = {-1, +1, 0, 0};
int diry[] = {0, 0, -1, +1};
void add(int grpid, int &count) {
  if (++cc[grpid] == 1) count += qtd[grpid];
}
void rem(int grpid, int &count) {
  if (--cc[grpid] == 0) count -= qtd[grpid];
}
int main() {
  ios::sync_with_stdio(0);
  while (cin >> n >> k) {
    for (int i = 0; i < n; ++i) {
      cin >> f[i];
    }
    memset(grp, -1, sizeof(grp));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (f[i][j] == '.' && grp[i][j] == -1) {
          queue<pair<int, int> > q;
          int grpid = i * n + j;
          grp[i][j] = grpid;
          qtd[grpid] = 1;
          q.push(pair<int, int>(i, j));
          while (!q.empty()) {
            int ci, cj;
            tie(ci, cj) = q.front();
            q.pop();
            for (int d = 0; d < dirlen; ++d) {
              int ni = ci + dirx[d];
              int nj = cj + diry[d];
              if (ni >= 0 && ni < n && nj >= 0 && nj < n && f[ni][nj] == '.' &&
                  grp[ni][nj] == -1) {
                grp[ni][nj] = grpid;
                qtd[grpid]++;
                q.push(make_pair(ni, nj));
              }
            }
          }
        } else if (f[i][j] != '.') {
          grp[i][j] = i * n + j;
          qtd[i * n + j] = 0;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      qtddot[i][n - 1] = (f[i][n - 1] == '.' ? 1 : 0);
      for (int j = n - 2; j >= 0; --j) {
        qtddot[i][j] = (f[i][j] == '.' ? 1 : 0) + qtddot[i][j + 1];
        if (j + k < n) qtddot[i][j] -= (f[i][j + k] == '.' ? 1 : 0);
      }
    }
    for (int j = 0; j < n; ++j) {
      qtddot2[n - 1][j] = qtddot[n - 1][j];
      for (int i = n - 2; i >= 0; --i) {
        qtddot2[i][j] = qtddot[i][j] + qtddot2[i + 1][j];
        if (i + k < n) qtddot2[i][j] -= qtddot[i + k][j];
      }
    }
    int best = 0;
    for (int i = 0; i + k - 1 < n; ++i) {
      memset(cc, 0, sizeof(cc));
      int count = 0;
      for (int ai = max(i - 1, 0); ai < n && ai <= i + k; ai++) {
        for (int aj = 0; aj < n && aj <= k; aj++) {
          if (!(aj == k && (ai == i - 1 || ai == i + k))) {
            add(grp[ai][aj], count);
          }
        }
      }
      for (int j = 0; j + k - 1 < n; ++j) {
        best = max(count + k * k - qtddot2[i][j], best);
        if (i > 0) {
          rem(grp[i - 1][j], count);
          if (j + k < n) {
            add(grp[i - 1][j + k], count);
          }
        }
        if (i + k < n) {
          rem(grp[i + k][j], count);
          if (j + k < n) {
            add(grp[i + k][j + k], count);
          }
        }
        if (j > 0) {
          for (int ai = i; ai < i + k; ++ai) {
            rem(grp[ai][j - 1], count);
          }
        }
        if (j + k + 1 < n) {
          for (int ai = i; ai < i + k; ++ai) {
            add(grp[ai][j + k + 1], count);
          }
        }
      }
    }
    cout << best << "\n";
  }
  return 0;
}
