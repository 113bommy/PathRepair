#include <bits/stdc++.h>
using namespace std;
int n;
int a[105];
int main() {
  cin >> n;
  long long ans = 1;
  bool flag = false;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) flag = true;
  }
  if (!flag) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 1)
      for (int j = i + 1; j < n; j++)
        if (a[j] == 1) {
          ans = ans * (j - i);
          break;
        }
  }
  cout << ans;
  return 0;
}
