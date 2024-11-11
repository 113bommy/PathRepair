#include <bits/stdc++.h>
using namespace std;
int m, ans[10005], q[5005];
int main() {
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int tmp;
    scanf("%d", &tmp);
    q[tmp]++;
  }
  int sz = 0;
  for (int i = 1; i <= 5000; ++i)
    if (q[i]) {
      ans[sz++] = i;
      q[i]--;
    }
  for (int i = ans[sz - 1] - 1; i > 0; --i)
    if (q[i]) ans[sz++] = i;
  printf("%d\n", sz);
  for (int i = 0; i < sz; ++i) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
