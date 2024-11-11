#include <bits/stdc++.h>

using namespace std;

long long ans;
int l[100002], r[100002], n;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> l[i] >> r[i];
  sort (l, l + n + 1, cmp);
  reverse(l, l + n + 1);
  sort (r, r + n + 1);
  for (int i = 0; i <= n; i++) {
    if (l[i] <= r[i]) break;
    ans += l[i] - r[i];
  }
  cout << ans * 2;
  return 0;
}
