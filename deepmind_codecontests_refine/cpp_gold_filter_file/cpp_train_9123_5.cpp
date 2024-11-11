#include <bits/stdc++.h>
using namespace std;
template <class A>
inline A Min(A &a, A &b) {
  return a < b ? a : b;
}
template <class A>
inline A Max(A &a, A &b) {
  return a > b ? a : b;
}
struct DATA {
  double l;
  long j;
  DATA(double l, long j) {
    this->l = l;
    this->j = j;
  }
};
long n, w, m;
vector<DATA> Ans[77];
long Milk[77];
int main(void) {
  long i, j = 0;
  scanf("%ld%ld%ld", &n, &w, &m);
  long Per_M = m / n;
  if (m % n) Per_M++;
  if (Per_M > 2) {
    printf("NO\n");
    return 0;
  }
  double Per_W = (1.0 * w * n) / m;
  double Left = 0;
  for (i = 1; i <= m; i++) {
    if (Left < 1e-10) {
      Left = w;
      j++;
    }
    double Need = Per_W;
    while (1) {
      if (Need - Left > 1e-10) {
        Ans[i].push_back(DATA(Left, j));
        Milk[j]++;
        Need -= Left;
        Left = w;
        j++;
        if (j > n) break;
      } else {
        Ans[i].push_back(DATA(Need, j));
        Milk[j]++;
        Left -= Need;
        break;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    if (Milk[i] > 2) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  for (i = 1; i <= m; i++) {
    for (j = 0; j < Ans[i].size(); j++) {
      if (j) printf(" ");
      printf("%ld %.6lf", Ans[i][j].j, Ans[i][j].l);
    }
    printf("\n");
  }
  return 0;
}
