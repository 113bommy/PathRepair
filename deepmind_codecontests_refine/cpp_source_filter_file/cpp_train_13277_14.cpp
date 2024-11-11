#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int ans = 1;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  for (int i = 0; i < n; i++)
    if (ans < a[i]) ans++;
  cout << ans + 1 << endl;
  return 0;
}
