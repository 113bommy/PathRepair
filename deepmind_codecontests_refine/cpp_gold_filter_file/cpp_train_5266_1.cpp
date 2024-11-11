#include <bits/stdc++.h>
using namespace std;
int a[1000010];
pair<int, int> b[1000010];
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &b[i].first);
    b[i].second = i;
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  int st = 1, dr = m + 1, poz = m + 2;
  for (; st <= dr;) {
    int mij = (st + dr) >> 1;
    int ind = 0, i = 1, j = mij;
    for (; i <= n || j <= m;) {
      if (i <= n && j <= m) {
        if (a[i] == b[j].first) {
          int zi = a[i] + 1;
          ind += 2;
          ++i;
          ++j;
          if (1LL * zi * k - 1LL * ind < 0) {
            ind = -1;
            break;
          }
        } else if (a[i] < b[j].first) {
          int zi = a[i] + 1;
          ++ind;
          ++i;
          if (1LL * zi * k - 1LL * ind < 0) {
            ind = -1;
            break;
          }
        } else if (a[i] > b[j].first) {
          int zi = b[j].first + 1;
          ++ind;
          ++j;
          if (1LL * zi * k - 1LL * ind < 0) {
            ind = -1;
            break;
          }
        }
      } else if (i <= n) {
        int zi = a[i] + 1;
        ++ind;
        ++i;
        if (1LL * zi * k - 1LL * ind < 0) {
          ind = -1;
          break;
        }
      } else if (j <= m) {
        int zi = b[j].first + 1;
        ++ind;
        ++j;
        if (1LL * zi * k - 1LL * ind < 0) {
          ind = -1;
          break;
        }
      }
    }
    if (ind == -1)
      st = mij + 1;
    else
      dr = mij - 1, poz = mij;
  }
  printf("%d\n", m - poz + 1);
  for (int i = poz; i <= m; ++i) printf("%d ", b[i].second);
  printf("\n");
  return 0;
}
