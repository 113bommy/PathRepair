#include <bits/stdc++.h>
using namespace std;
int n, ary[101], found[101], cnt, last, ans;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ary[i];
    ++found[ary[i]];
  }
  for (int j = 0; j < n; j++) {
    cnt = 0;
    for (int i = 0; i <= 100; i++)
      if (found[i] >= 2) found[i] -= 2, ++cnt, last = i;
    if (cnt & 1) found[last] += 2;
    ans += cnt / 2;
  }
  for (int i = 0; i <= 100; i++)
    if (found[i] >= 4) ans += found[i] / 4, found[i] -= 4;
  cout << ans << "\n";
  return 0;
}
