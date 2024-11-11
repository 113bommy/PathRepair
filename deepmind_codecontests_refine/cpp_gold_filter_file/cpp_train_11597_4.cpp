#include <bits/stdc++.h>
using namespace std;
int n, i, dim, v, wh[100011];
int a[100011], sol[2][100011];
vector<pair<int, int> > ord;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    scanf("%d", &a[i]), ord.push_back(make_pair(a[i], i));
  sort(ord.begin(), ord.end());
  for (i = 1; i <= n; i++) a[i] = ord[i - 1].first, wh[ord[i - 1].second] = i;
  if (n == 1) {
    printf("YES\n0\n%d", a[1]);
    return 0;
  }
  dim = (n + 2) / 3;
  for (i = 1; i <= dim; i++) {
    sol[0][i] = i - 1;
    sol[1][i] = a[i] - (i - 1);
  }
  for (i = dim + 1; i <= 2 * dim; i++) {
    sol[1][i] = i - 1;
    sol[0][i] = a[i] - (i - 1);
  }
  v = dim - 1;
  for (i = 2 * dim + 1; i <= n; i++, v--) {
    sol[1][i] = v;
    sol[0][i] = a[i] - v;
  }
  printf("YES\n");
  for (i = 1; i <= n; i++) printf("%d ", sol[0][wh[i]]);
  printf("\n");
  for (i = 1; i <= n; i++) printf("%d ", sol[1][wh[i]]);
  return 0;
}
