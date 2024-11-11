#include <bits/stdc++.h>
using namespace std;
int n, k, a[1010];
long res = 1e9 + 7;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long tmp, gt;
  int flag = 1;
  for (int i = 2; i <= n; i++)
    if (a[i] - a[i - 1] != k) {
      flag = 0;
      break;
    }
  if (flag) {
    cout << 0;
    return 0;
  }
  for (int t = 1; t <= 1000; t++) {
    tmp = 0;
    if (a[1] != t) tmp++;
    for (int i = 2; i <= n; i++)
      if (a[i] != t + (i - 1) * k) tmp++;
    if (tmp < res) {
      res = tmp;
      gt = t;
    }
  }
  cout << gt << endl;
  for (int i = 1; i <= n; i++)
    if (a[i] != gt + (i - 1) * k) {
      if (a[i] < gt + (i - 1) * k)
        cout << "+ " << i << " " << gt + (i - 1) * k - a[i] << endl;
      else
        cout << "- " << i << " " << a[i] - (gt + (i - 1) * k) << endl;
    }
}
