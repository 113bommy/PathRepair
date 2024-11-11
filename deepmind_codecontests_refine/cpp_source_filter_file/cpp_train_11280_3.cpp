#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 1e3 + 10, MOD = 1e9 + 7;
int n, m, k, add[N], current;
vector<int> res;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    res.push_back(1);
  }
  for (int i = n + 1; i <= n + m; i++) {
    current += add[i];
    if (current == 0) {
      current = 1;
      res.push_back(i - 1);
      add[i + n - 1]--;
    }
    while (current < k) {
      res.push_back(i);
      add[i + n]--;
      current++;
    }
  }
  if (res[res.size() - 1] + n - 1 < n + m + 1) res.push_back(n + m - 1);
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) printf("%d ", res[i]);
  return 0;
}
