#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int main() {
  int n, k;
  cin >> n >> k;
  long long ans = 0, tmp = 1;
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i - 1])
      tmp = 1;
    else
      tmp++;
    ans = max(tmp, ans);
  }
  cout << ans;
  return 0;
}
