#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, i, cnt = 0, s = 0, x;
  cin >> n;
  for (i = 0; i < n; i++) cin >> x, s += x;
  for (i = 1; i <= 5; i++)
    if ((s + i) % (n + 1) != 1) cnt++;
  cout << cnt << "\n";
}
