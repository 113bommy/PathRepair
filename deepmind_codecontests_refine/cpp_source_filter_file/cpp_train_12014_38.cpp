#include <bits/stdc++.h>
using namespace std;
int n, ans[100005];
bitset<10000005> b;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  b.set();
  int cnt = 0;
  for (int i = 2; i < 10000005; i++) {
    if (b[i]) {
      ans[cnt++] = i;
      if (cnt == n) {
        for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
        return 0;
      }
      for (int j = i + i; j < 100005; j += i) {
        b[j] = false;
      }
    }
  }
  return 0;
}
