#include <bits/stdc++.h>
using namespace std;
int a[1000006], cnt[1000006], b[1000006];
int main() {
  int n, m, t;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t);
    b[i] = t;
    if (t <= m) a[t]++;
  }
  for (int i = 1; i <= m; i++) {
    if (a[i])
      for (int j = i; j <= m; j += i) cnt[j] += a[i];
  }
  int max = 1;
  for (int i = 1; i <= m; i++)
    if (cnt[max] < cnt[i]) max = i;
  cout << max << ' ' << cnt[max] << endl;
  int flag = 1;
  for (int i = 1; i <= n; i++) {
    if (max % b[i] == 0) {
      if (flag)
        flag = 0, printf("%d", i);
      else
        printf(" %d", i);
    }
  }
  return 0;
}
