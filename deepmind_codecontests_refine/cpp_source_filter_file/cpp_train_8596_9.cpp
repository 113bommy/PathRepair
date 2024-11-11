#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, k, i, sum;
  sum = 0;
  cin >> n >> k;
  int a[n + 1];
  int b[n + 1];
  vector<pair<int, int> > res(n + 1);
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) cin >> b[i];
  for (i = 1; i <= n; i++) {
    res[i].first = a[i] - b[i];
    res[i].second = i;
  }
  sort(res.begin(), res.end());
  for (i = 1; i <= k; i++) sum += a[res[i].second];
  for (i = k + 1; i <= n; i++)
    sum += res[i].first > 0 ? b[res[i].second] : a[res[i].second];
  printf("%d", sum);
  char ch = getchar();
  ch = getchar();
}
