#include <bits/stdc++.h>
using namespace std;
long long k;
int pre, a[500], wins[501], mx = 0, n, i;
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    mx = max(a[i], mx);
  }
  if (k >= n) {
    printf("%d\n", mx);
    return 0;
  }
  pre = a[0];
  for (i = 1; wins[pre] < k; i++) {
    if (a[i] > pre) {
      wins[a[i]]++;
      pre = a[i];
    } else {
      wins[pre]++;
    }
    if (i == n - 1) i = -1;
  }
  if (wins[pre] == k)
    cout << pre << endl;
  else
    cout << a[i] << endl;
  return 0;
}
