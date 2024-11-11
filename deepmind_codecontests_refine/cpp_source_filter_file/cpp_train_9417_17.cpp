#include <bits/stdc++.h>
using namespace std;
int arr[3000005] = {0};
int main() {
  int n;
  scanf("%d", &n);
  int mx = -1;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    arr[x] = 1;
    mx = max(x, mx);
  }
  int last = -1;
  for (int i = 1; i < 3000005; i++) {
    if (arr[i]) last = i;
    arr[i] = last;
  }
  int ans = -1;
  for (int i = 1; i < mx; i++) {
    if (arr[i] == i) {
      int x = -1;
      for (int j = i * 2; j <= 2 * mx; j += i) {
        x = max(x, arr[j] % i);
        if (x == i - 1) break;
      }
      ans = max(ans, x);
    }
  }
  cout << ans << endl;
}
