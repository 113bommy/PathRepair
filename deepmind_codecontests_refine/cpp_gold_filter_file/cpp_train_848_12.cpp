#include <bits/stdc++.h>
int dr[] = {2, 2, -2, -2, 1, -1, 1, -1};
int dc[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dr1[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dc1[] = {1, -1, 1, 0, -1, 0, 1, -1};
int dr2[] = {0, 0, 1, -1};
int dc2[] = {1, -1, 0, 0};
using namespace std;
long long a[500005], b[500005], mark[500005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc, n, i, j, m;
  cin >> tc;
  while (tc--) {
    cin >> n >> m;
    vector<long long> v;
    for (i = 1; i <= n * 3; i++) mark[i] = 0;
    for (i = 1; i <= m; i++) {
      long long x, y;
      cin >> x >> y;
      if (mark[x] == 1 || mark[y] == 1) continue;
      mark[x] = mark[y] = 1;
      v.push_back(i);
    }
    if (v.size() >= n) {
      cout << "Matching" << endl;
      for (i = 0; i < n; i++) cout << v[i] << " ";
      cout << endl;
    } else {
      cout << "IndSet" << endl;
      long long cn = n;
      for (i = 1; i <= n * 3; i++) {
        if (cn == 0) break;
        if (mark[i] == 0) {
          cout << i << " ";
          cn--;
        }
      }
      cout << endl;
    }
  }
  return 0;
}
