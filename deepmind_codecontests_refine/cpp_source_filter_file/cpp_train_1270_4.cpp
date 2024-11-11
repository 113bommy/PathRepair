#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int main() {
  int N;
  cin >> N;
  while (N--) {
    int a[200005];
    int n;
    cin >> n;
    int ans = inf, l = 0;
    for (int i = 0; i < n; i++) a[i] = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (a[x]) {
        ans = min(ans, i - a[x] + 1);
      }
      a[x] = i;
    }
    cout << (ans == inf ? -1 : ans) << endl;
  }
  return 0;
}
