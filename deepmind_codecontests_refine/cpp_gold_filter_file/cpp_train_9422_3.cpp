#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int pos[maxn];
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      pos[x] = i + 1;
    }
    int ans = n - 1, cnt = 1;
    for (int i = 1; i < n; i++) {
      cnt = pos[i + 1] > pos[i] ? cnt + 1 : 1;
      ans = min(ans, n - cnt);
    }
    cout << ans << "\n";
  }
  return 0;
}
