#include <bits/stdc++.h>
using namespace std;
int cnt[1000005] = {0};
int a[1000005];
int divi[1000005] = {0};
int main() {
  int n, m, q, t = 0, cd = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] <= m) {
      cd = 1;
      cnt[a[i]]++;
    }
  }
  if (!cd) {
    cout << "1 0" << endl;
    return 0;
  }
  for (int i = 1; i <= m; ++i) {
    if (cnt[i] > 0)
      for (int j = i; j <= m; j += i) divi[j] += cnt[i];
  }
  int ans = 0, id = -1;
  for (int i = 1; i <= m; ++i)
    if (divi[i] > ans) ans = divi[i], id = i;
  printf("%d %d\n", id, ans);
  for (int i = 1; i <= n; ++i)
    if (id % a[i] == 0) printf("%d ", i);
  printf("\n");
  return 0;
}
