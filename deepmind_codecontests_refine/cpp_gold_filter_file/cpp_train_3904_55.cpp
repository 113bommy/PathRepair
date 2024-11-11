#include <bits/stdc++.h>
using namespace std;
const int INF = 1e5;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int ans = INF, t1, t2;
  int x, y;
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &x, &y);
    t1 = min(x, y);
    t2 = min(n + 1 - x, m + 1 - y);
    t1 = min(t1, t2);
    ans = min(ans, t1);
  }
  if (ans <= 5)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
