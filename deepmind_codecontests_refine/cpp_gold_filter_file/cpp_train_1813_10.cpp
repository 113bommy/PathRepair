#include <bits/stdc++.h>
using namespace std;
int ans[3000 * 3000 + 1];
int main() {
  int n;
  cin >> n;
  int a[5000];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int inv = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j]) inv++;
    }
  }
  ans[0] = 0;
  ans[1] = 1;
  for (int i = 2; i <= inv; i++) {
    ans[i] = ans[i - 2] + 4;
  }
  cout << ans[inv];
  return 0;
}
