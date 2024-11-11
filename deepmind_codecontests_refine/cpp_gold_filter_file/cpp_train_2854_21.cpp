#include <bits/stdc++.h>
using namespace std;
const int maxx = 1e5 + 20;
int a[maxx];
int main() {
  int n, s = 0, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 2; i < n; i++) {
    if (a[i] == a[i - 1] + a[i - 2])
      s++;
    else {
      ans = max(ans, s);
      s = 0;
    }
  }
  ans = max(ans, s);
  cout << min(ans + 2, n) << endl;
  return 0;
}
