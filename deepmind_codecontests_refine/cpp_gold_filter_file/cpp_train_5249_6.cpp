#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  int count = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a == 1) {
      if (m == 0)
        count++;
      else
        m--;
    } else {
      if (k == 0) {
        if (m == 0)
          count++;
        else
          m--;
      } else
        k--;
    }
  }
  cout << count << '\n';
  return 0;
}
