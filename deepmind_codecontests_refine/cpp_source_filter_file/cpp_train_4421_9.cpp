#include <bits/stdc++.h>
using namespace std;
int n, a[1001], ans, id[1001];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      ans++;
      id[ans] = i;
    }
  }
  if (ans == 0) {
    cout << 0;
    return 0;
  }
  ans = 0;
  for (int i = id[1]; i <= n; i++) {
    if (a[i + 1] == 1 && i != n) {
      ans++;
      continue;
    }
    for (int j = i; j <= n; j++) {
      if (a[j] == 1 && j != i) {
        ans += 2;
        i = j;
        break;
      }
    }
  }
  cout << ans + 1;
  return 0;
}
