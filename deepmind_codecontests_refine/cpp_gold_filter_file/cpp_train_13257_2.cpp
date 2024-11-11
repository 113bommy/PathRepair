#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > out;
vector<pair<int, int> >::iterator iter;
long long int a[3][200005];
int main() {
  long long int x[3], y[3], m[3];
  int k[3], i, j, bad = 0, prev = 0, n, u = 1, v = 1;
  bool A, B;
  scanf("%d", &n);
  for (i = 1; i <= 2; i++) {
    scanf("%d%I64d%I64d%I64d%I64d", &k[i], &a[i][1], &x[i], &y[i], &m[i]);
    for (j = 2; j <= k[i]; j++) a[i][j] = (a[i][j - 1] * x[i] + y[i]) % m[i];
  }
  for (i = 1; i <= k[1] + k[2]; i++) {
    A = B = false;
    if (((u <= k[1] && a[1][u] < prev) && (v <= k[2] && a[2][v] < prev)) ||
        (v > k[2] && a[1][u] < prev) || (u > k[1] && a[2][v] < prev)) {
      bad++;
      if ((u <= k[1] && a[1][u] < a[2][v]) || v > k[2])
        A = true;
      else
        B = true;
    }
    if (u <= k[1] && !B &&
        (((a[2][v] < prev) || A) ||
         ((v > k[2]) || (a[1][u] >= prev && a[1][u] < a[2][v])))) {
      if (k[1] + k[2] <= 200000) out.push_back(make_pair(a[1][u], 1));
      prev = a[1][u];
      u++;
    } else {
      if (k[1] + k[2] <= 200000) out.push_back(make_pair(a[2][v], 2));
      prev = a[2][v];
      v++;
    }
  }
  printf("%d\n", bad);
  if (k[1] + k[2] <= 200000) {
    for (iter = out.begin(); iter != out.end(); iter++)
      printf("%d %d\n", iter->first, iter->second);
  }
}
