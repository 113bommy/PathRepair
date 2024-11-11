#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<pair<int, int> > v(10002);
  int a, n, b, x, i, count = 2;
  cin >> n >> a;
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &x, &b);
    v[i].first = x;
    v[i].second = b;
  }
  sort(v.begin(), v.begin() + n);
  if (n > 1) {
    for (i = 1; i <= n - 1; i++)
      if (v[i].first + v[i].second / 2.0 + a <
          v[i + 1].first - v[i + 1].second / 2.0)
        count += 2;
      else if (v[i].first + v[i].second / 2.0 + a ==
               v[i + 1].first - v[i + 1].second / 2.0)
        count++;
  }
  printf("%d\n", count);
  return 0;
}
