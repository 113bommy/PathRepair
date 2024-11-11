#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
int n, m;
int f[105];
int ok(int k) {
  int t1 = 0;
  for (int i = 1; i <= 100; i++) {
    t1 += f[i] / k;
  }
  return (t1 >= n);
}
int main() {
  std::ios::sync_with_stdio(0);
  int i, j, k, t1, t2, t3;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> t1;
    f[t1]++;
  }
  for (i = 1; i <= m; i++) {
    if (!ok(i)) break;
  }
  cout << i - 1 << '\n';
}
