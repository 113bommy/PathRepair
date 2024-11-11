#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int comp(const void *i, const void *j) { return *(int *)i - *(int *)j; }
int main() {
  int n, m, s, d;
  cin >> n >> m >> s >> d;
  int z = 0;
  int *A = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> z;
    A[i] = z;
  }
  qsort(A, n, sizeof(int), comp);
  int i, x;
  int max = 0;
  int p;
  for (i = 0; i < n; i++) {
    x = A[i];
    p = x;
    while ((x + 1) + s >= A[i + 1] && i < n - 1) {
      x = A[i + 1];
      i++;
    }
    if (max < (x - p)) max = x - p;
  }
  int y = 0;
  if ((max + 2 > d) || max + 2 > (m - s))
    cout << "IMPOSSIBLE" << endl;
  else if (A[0] - s <= 0)
    cout << "IMPOSSIBLE" << endl;
  else {
    for (int i = 0; i < n; i++) {
      p = 0;
      x = A[i];
      cout << "RUN " << x - y - 1 << endl;
      y = x;
      while (((x + 1) + s >= A[i + 1]) && (i < n - 1)) {
        x = A[i + 1];
        i++;
        p++;
        if ((A[i + 1] - d) >= max) {
          break;
        }
      }
      cout << "JUMP " << x - y + 2 << endl;
      y = x + 1;
    }
    if ((m - x - 1) > 0) cout << "RUN " << m - x - 1 << endl;
  }
  return 0;
}
