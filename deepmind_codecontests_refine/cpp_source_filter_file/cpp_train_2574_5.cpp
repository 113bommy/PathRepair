#include <bits/stdc++.h>
using namespace std;
int maxn = 2 * 100000 + 2;
int x[2 * 100000 + 2];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int k = n / m;
  int i;
  vector<vector<int> > val(m);
  for (i = 1; i <= n; i++) {
    scanf("%d", &x[i]);
    val[x[i] % m].push_back(i);
  }
  long long ans = 0;
  vector<pair<int, int> > fre;
  for (i = 0; i < 2 * m; i++) {
    int p = i % m;
    int count = 0;
    int j;
    while (val[p].size() > k) {
      int elm = val[p].back();
      val[p].pop_back();
      fre.push_back(make_pair(elm, i));
    }
    while (val[p].size() < k && !fre.empty()) {
      int elm = fre.back().first;
      int mm = fre.back().second;
      ans += i - mm;
      x[elm] += i - mm;
      fre.pop_back();
      val[p].push_back(elm);
    }
  }
  printf("%d\n", ans);
  for (i = 1; i <= n; i++) printf("%d ", x[i]);
  printf("\n");
  return 0;
}
