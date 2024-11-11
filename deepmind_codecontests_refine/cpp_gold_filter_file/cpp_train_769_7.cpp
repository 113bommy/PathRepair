#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
int n, A[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", A + i);
  }
  sort(A, A + n);
  int l = (n - 1) / 2, r = n - 1;
  int ans = n;
  while (l >= 0 && r > (n - 1) / 2) {
    if (A[r] >= 2 * A[l]) {
      ans--;
      r--;
      l--;
    } else {
      l--;
    }
  }
  cout << ans << endl;
  return 0;
}
