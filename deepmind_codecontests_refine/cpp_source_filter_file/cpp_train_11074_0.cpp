#include <bits/stdc++.h>
using namespace std;
const int M1 = 100030;
const int M2 = 316;
bool pri[M1];
void se() {
  int i, j, k;
  pri[1] = 1;
  for (k = 1, i = 2; i <= M2; i += k, k = 2)
    if (!pri[i]) {
      for (j = i * i; j < M1; j += i * 2) pri[j] = 1;
    }
}
int pr(int n) {
  int i, j = 0;
  for (i = n;; i++)
    if (!pri[i])
      return j;
    else
      j++;
}
int main() {
  se();
  int i, j, k = 100000, n, m, l, p;
  cin >> n >> m;
  int a[n][m];
  for (i = 0; i < n; i++) {
    for (p = 0, j = 0; j < m; j++) {
      cin >> l;
      a[i][j] = pr(l);
      p += a[i][j];
    }
    k = min(k, p);
  }
  if (k == 0) {
    cout << "0\n";
  } else {
    for (i = 0; i < m; i++) {
      for (l = 0, j = 0; j < n; j++) l += a[j][i];
      k = min(k, l);
    }
    cout << k << "\n";
  }
}
