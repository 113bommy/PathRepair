#include <bits/stdc++.h>
using namespace std;
int a[100 + 10];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int t, ans = 10000000;
  for (int i = 0; i <= 102; i++) {
    int tmp = 0;
    for (int j = 0; j < n; j++) {
      if (abs(a[j] - i) != 0) tmp += abs(a[j] - i) - 1;
    }
    if (tmp < ans) {
      ans = tmp;
      t = i;
    }
  }
  cout << t << " " << ans << endl;
  return 0;
}
