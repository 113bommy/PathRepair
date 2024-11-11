#include <bits/stdc++.h>
using namespace std;
const int MAXM = 50;
const int MAXN = 1000 + 10;
int N, M;
int a[MAXN], res[MAXN];
int main() {
  cin >> N >> M;
  int i, j;
  for (i = (1); i <= (M); ++i) {
    cin >> a[i];
  }
  int ok = 1;
  for (i = (1); i <= (N); ++i) {
    ok = 0;
    for (j = (1); j <= (M); ++j) {
      if (a[j] && j != res[i - 1] && (i < N || j != res[1])) {
        if (i > 1) {
          if (j != res[1] || a[j] > a[ok]) ok = j;
        } else {
          if (a[j] < a[ok] || !ok) ok = j;
        }
      }
    }
    if (!ok) break;
    a[ok]--;
    res[i] = ok;
  }
  if (!ok)
    cout << -1 << endl;
  else {
    for (i = (1); i <= (N); ++i) {
      printf("%d", res[i]);
      if (i < N)
        printf(" ");
      else
        printf("\n");
    }
  }
  return 0;
}
