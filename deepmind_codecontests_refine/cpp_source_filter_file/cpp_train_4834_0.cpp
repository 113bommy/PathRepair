#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> d(m);
  for (int i = 0; i < m; ++i) cin >> d[i];
  vector<int> w(k);
  for (int i = 0; i < k; ++i) cin >> w[i];
  vector<int> r(m);
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < k; ++j)
      if (w[j] % d[i] == 0) r[i]++;
  int q = *max_element(r.begin(), r.end());
  int c = 0;
  for (int i = 0; i < m; ++i)
    if (r[i] == q) c++;
  printf("%d\n", c);
  for (int i = 0; i < m; ++i)
    if (r[i] == q) printf("%d ", i + 1);
  return 0;
}
