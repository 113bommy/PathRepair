#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const int N = (int)1e5 + 5;
using namespace std;
int t, n;
int a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t;
  a[0] = -1;
  while (t--) {
    cin >> n;
    for (int i = (1); i < (n + 1); i++) cin >> a[i];
    if (n % 2 == 0) {
      puts("YES");
      continue;
    } else {
      bool ans = false;
      for (int i = (1); i < (n + 1); i++) {
        if (a[i] < a[i - 1]) {
          ans = true;
          break;
        }
      }
      puts(ans ? "YES" : "NO");
    }
  }
  return 0;
}
