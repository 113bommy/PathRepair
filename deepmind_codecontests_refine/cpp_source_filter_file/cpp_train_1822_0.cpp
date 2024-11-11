#include <bits/stdc++.h>
using namespace std;
int n, a[100005];
bool avail[100005], ok[100005];
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n - 1; ++i) scanf("%d", &a[i]);
  memset(avail, true, sizeof(avail));
  for (int i = 0; i <= n - 1; ++i)
    if (a[i] <= n && avail[a[i]]) {
      ok[i] = true;
      avail[a[i]] = false;
    }
  int j = 1;
  for (int i = 0; i <= n - 1; ++i)
    if (ok[i]) {
      while (!avail[j]) ++j;
      a[i] = j;
      ++j;
    }
  for (int i = 0; i <= n - 1; ++i) printf("%d ", a[i]);
  return 0;
}
