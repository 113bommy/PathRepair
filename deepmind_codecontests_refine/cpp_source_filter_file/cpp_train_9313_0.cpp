#include <bits/stdc++.h>
using namespace std;
int ar[1000010], ans[1000010], cnt[1000010];
int main() {
  int n, x, y;
  cin >> n;
  if (n == 2) {
    int a, b;
    cin >> x >> y;
    cin >> a >> b;
    if (x == 0)
      cout << a << " " << y << "\n";
    else
      cout << x << " " << b << "\n";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    ar[x] = y;
    cnt[x]++;
    cnt[y]++;
  }
  int f = 0;
  for (int i = 1; i <= 1000000; i++) {
    if (cnt[i] == 1) {
      f = i;
      break;
    }
  }
  ans[1] = f;
  for (int i = 3;; i += 2) {
    if (ar[ans[i - 2]] == 0) break;
    ans[i] = ar[ans[i - 2]];
  }
  for (int i = 2;; i += 2) {
    if (ar[ans[i - 2]] == 0) break;
    ans[i] = ar[ans[i - 2]];
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << "\n";
  return 0;
}
