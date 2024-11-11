#include <bits/stdc++.h>
using namespace std;
int n;
int d[200], x, y, res;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 2; i <= n; i++) cin >> d[i];
  cin >> x >> y;
  for (int i = x; i <= y; i++) res += d[i];
  cout << res;
  return 0;
}
