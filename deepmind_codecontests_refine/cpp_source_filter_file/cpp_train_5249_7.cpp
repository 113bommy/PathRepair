#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> k >> m >> n;
  int count = 0;
  for (int i = 0; i < k; i++) {
    int a;
    cin >> a;
    if (a == 1) {
      if (m == 0)
        count++;
      else
        m--;
    } else {
      if (m == 0) {
        if (n == 0)
          count++;
        else
          n--;
      } else
        m--;
    }
  }
  cout << count << '\n';
  return 0;
}
