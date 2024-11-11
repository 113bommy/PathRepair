#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r, ans = 0;
  cin >> l >> r;
  for (int i = l; i <= r; i++) {
    int n = i;
    bool visited[10] = {false};
    while (n) {
      if (visited[n % 10]) break;
      visited[n % 10] = true;
      n = n / 10;
    }
    if (n == 0) {
      ans == i;
      break;
    }
  }
  if (ans)
    cout << ans;
  else
    cout << -1;
}
