#include <bits/stdc++.h>
using namespace std;
int n, t, a, fix[300005], ans, ans1, i;
int main() {
  cin >> n;
  ans = n;
  ans1 = n;
  cout << 1 << " ";
  for (i = 0; i < n; i++) {
    scanf("%d", &a);
    ans1--;
    fix[a] = 1;
    while (fix[ans] == 1) ans--;
    cout << ans - ans1 + 1 << " ";
  }
  return 0;
}
