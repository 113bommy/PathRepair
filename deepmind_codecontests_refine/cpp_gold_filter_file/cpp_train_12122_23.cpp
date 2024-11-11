#include <bits/stdc++.h>
using namespace std;
int main() {
  int but[101] = {0};
  int n, m, b, cur;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b;
    cur = b;
    for (b; b <= n; b++)
      if (but[b] == 0) but[b] = cur;
  }
  for (int i = 1; i <= n; i++) cout << but[i] << " ";
  cout << endl;
  return 0;
}
