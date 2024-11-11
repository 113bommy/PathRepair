#include <bits/stdc++.h>
using namespace std;
int n;
int a[100];
int ans[100][2];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  ans[n - 1][0] = 0;
  ans[n - 1][1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    if (a[i + 1] + ans[i + 1][0] <= ans[i + 1][1]) {
      ans[i][1] = ans[i + 1][1];
      ans[i][0] = ans[i + 1][0] + a[i];
    } else {
      ans[i][0] = ans[i + 1][1];
      ans[i][1] = ans[i + 1][0] + a[i];
    }
  }
  cout << ans[0][0] << " " << ans[0][1] << endl;
}
