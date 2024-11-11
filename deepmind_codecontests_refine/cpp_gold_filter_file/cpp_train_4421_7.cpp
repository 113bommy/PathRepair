#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = -1, ans = 0;
  int a[1100];
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 1) {
      k++;
      a[k] = i;
    }
  }
  for (int i = 0; i < k; i++)
    if (a[i + 1] - a[i] == 1)
      ans++;
    else
      ans += 2;
  if (k != -1) ans++;
  cout << ans << endl;
  return 0;
}
