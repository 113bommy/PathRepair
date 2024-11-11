#include <bits/stdc++.h>
using namespace std;
int a[602];
int main() {
  int n, ans = 0, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x != 0) {
      a[x]++;
    }
  }
  sort(a, a + 601, greater<int>());
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) ans++;
    if (a[i] == 0) break;
  }
  cout << ans;
}
