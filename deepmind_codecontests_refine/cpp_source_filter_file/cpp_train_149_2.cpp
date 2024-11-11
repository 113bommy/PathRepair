#include <bits/stdc++.h>
using namespace std;
long long n, m, w[1000], day[2000], a[1000], k = 0, ans = 0, p = 0, tmp;
bool mas[1000];
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> w[i];
  for (int i = 1; i <= m; i++) {
    cin >> day[i];
    if (mas[day[i]] == false) {
      mas[day[i]] = true;
      k++;
      a[k] = day[i];
    }
  }
  for (int i = 2; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (j == day[i]) {
        p = j;
        break;
      }
      ans += w[a[j]];
    }
    for (int j = 2; j <= p; j++) {
      a[j] = a[j - 1];
    }
    a[1] = day[i];
  }
  cout << ans;
  return 0;
}
