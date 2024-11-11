#include <bits/stdc++.h>
using namespace std;
int n, m, p[50];
int main() {
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    cout << 1 << endl;
    fflush(stdout);
    cin >> p[i];
    if (p[i] == 0) return 0;
    if (p[i] == 1)
      p[i] = 0;
    else
      p[i] = 1;
  }
  int low = 1, high = m, cnt = 1;
  while (high >= low) {
    int mid = (high + low) / 2;
    cout << mid << endl;
    fflush(stdout);
    int x;
    cin >> x;
    if (x == 0) return 0;
    if (x == -1) {
      if (p[cnt])
        low = mid + 1;
      else
        high = mid - 1;
    } else {
      if (p[cnt])
        high = mid - 1;
      else
        low = mid + 1;
    }
    cnt++;
    if (cnt == n + 1) cnt = 1;
  }
}
