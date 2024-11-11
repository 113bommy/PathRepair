#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  if (n % 4 == 2 || n % 4 == 3) {
    cout << -1;
    return 0;
  }
  int ans[n + 10];
  if (n % 4 == 1) {
    ans[n / 2 + 1] = n / 2 + 1;
  }
  for (int i = 1; i < n / 2; i += 2) {
    ans[i] = i + 1;
    ans[i + 1] = n + 1 - i;
    ans[n + 1 - i] = n - i;
    ans[n - i] = i;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
