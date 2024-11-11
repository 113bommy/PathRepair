#include <bits/stdc++.h>
using namespace std;
int n, ml, mr, dd[200];
int main() {
  scanf("%d ", &n);
  scanf("%d %d", &ml, &mr);
  for (int i = 2; i <= n; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    for (int j = l; j <= r - 1; ++j) dd[j] = 1;
  }
  int res = 0;
  for (int i = ml; i <= mr - 1; ++i)
    if (!dd[i]) ++res;
  cout << res;
  return 0;
}
