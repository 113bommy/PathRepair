#include <bits/stdc++.h>
using namespace std;
int arr[100009];
int ans[100009];
int main() {
  int t, n, i;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> arr[i];
    ans[i] = min(i, n - i + 1);
  }
  for (i = 1; i <= n; i++) {
    ans[i] = min(ans[i], arr[i]);
  }
  for (i = 2; i <= n; i++) {
    ans[i] = min(ans[i], ans[i - 1] + 1);
  }
  for (i = n - 1; i >= 1; i--) {
    ans[i] = min(ans[i], ans[i + 1] + 1);
  }
  int a = 0;
  for (i = 1; i <= n; i++) {
    a = max(a, ans[i]);
  }
  cout << a;
  return 0;
}
