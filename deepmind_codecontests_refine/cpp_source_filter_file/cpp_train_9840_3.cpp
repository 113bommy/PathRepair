#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n;
pair<int, int> mp[N];
long long a[N], b[N];
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++)
    scanf("%lld", &a[i]), a[i] += a[i - 1];
  for (int i = (int)(1); i <= (int)(n); i++)
    scanf("%lld", &b[i]), b[i] += b[i - 1];
  bool fl = (a[n] > b[n]);
  for (int i = (int)(1); i <= (int)(n); i++)
    if (fl) swap(a[i], b[i]);
  for (int i = (int)(0); i <= (int)(n - 1); i++) mp[i] = pair<int, int>(-1, -1);
  int p = 0;
  for (int i = (int)(0); i <= (int)(n); i++) {
    for (; b[p] < a[i]; ++p)
      ;
    if (mp[b[p] - a[i]].first == -1)
      mp[b[p] - a[i]] = pair<int, int>(i, p);
    else {
      int v = b[p] - a[i];
      if (fl) {
        printf("%d\n", i - mp[v].first);
        for (int j = (int)(mp[v].first + 1); j <= (int)(i); j++)
          printf("%d ", j);
        puts("");
      }
      printf("%d\n", p - mp[v].second);
      for (int j = (int)(mp[v].second + 1); j <= (int)(p); j++)
        printf("%d ", j);
      puts("");
      if (!fl) {
        printf("%d\n", i - mp[v].first);
        for (int j = (int)(mp[v].first + 1); j <= (int)(i); j++)
          printf("%d ", j);
        puts("");
      }
      exit(0);
    }
  }
}
