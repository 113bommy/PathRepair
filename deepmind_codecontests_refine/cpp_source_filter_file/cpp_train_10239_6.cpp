#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int a[maxn], n;
long long lefts[maxn][2], rights[maxn][2];
long long ans;
inline int gao(int k) {
  if (k % 2)
    return k - 1;
  else
    return k;
}
inline int gao2(int k) {
  if (k % 2)
    return k;
  else
    return k - 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] > 1)
      lefts[i][0] = lefts[i - 1][0] + gao(a[i - 1]);
    else
      lefts[i][0] = 0;
    lefts[i][1] = max(lefts[i][0], gao2(a[i - 1]) + lefts[i - 1][1]);
  }
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] > 1)
      rights[i][0] = rights[i + 1][0] + gao(a[i + 1]);
    else
      rights[i][0] = 0;
    rights[i][1] = max(rights[i][0], gao2(a[i]) + rights[i + 1][1]);
  }
  for (int i = 1; i <= n; i++)
    ans = max(ans, max(rights[i][0] + lefts[i][1], lefts[i][0] + rights[i][1]));
  cout << ans << endl;
  return 0;
}
