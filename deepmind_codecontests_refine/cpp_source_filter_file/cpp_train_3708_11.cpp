#include <bits/stdc++.h>
using namespace std;
int64_t *arry[3];
int main(void) {
  int64_t n, p, q, r;
  cin >> n >> p >> q >> r;
  for (int i = 0; i < 3; i++) {
    arry[i] = (int64_t *)malloc(sizeof(int64_t) * n);
  }
  for (int i = 0; i < n; i++) {
    int buf;
    cin >> buf;
    arry[0][i] = buf * p;
    arry[1][i] = buf * q;
    arry[2][i] = buf * r;
  }
  {
    int64_t *pt = (int64_t *)malloc(sizeof(int64_t) * n);
    pt[n - 1] = arry[2][n - 1];
    for (int i = n - 1; i > 0; i--) {
      pt[i - 1] = max(pt[i], arry[2][i]);
    }
    free(arry[2]);
    arry[2] = pt;
  }
  {
    int64_t *pt = (int64_t *)malloc(sizeof(int64_t) * n);
    for (int i = 0; i < n; i++) {
      pt[i] = arry[1][i] + arry[2][i];
    }
    free(arry[1]);
    arry[1] = pt;
  }
  {
    int64_t *pt = (int64_t *)malloc(sizeof(int64_t) * n);
    pt[0] = *arry[0];
    for (int i = 1; i < n; i++) {
      pt[i] = max(pt[i - 1], arry[0][i]);
    }
    free(arry[0]);
    arry[0] = pt;
  }
  int64_t max = arry[0][0] + arry[1][0];
  for (int i = 1; i < n; i++) {
    int64_t buf = arry[0][i] + arry[1][i];
    if (buf > max) max = buf;
  }
  cout << max << endl;
  for (int i = 0; i < 3; i++) {
    free(arry[i]);
  }
}
