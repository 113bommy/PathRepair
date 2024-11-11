#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, ct = 0;
  cin >> n >> m;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j)
      if (pow(i, 2) + j == n and i + pow(j, 2) == m) ct++;
  cout << ct << endl;
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  return 0;
}
