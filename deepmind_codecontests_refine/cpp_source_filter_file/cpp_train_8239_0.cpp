#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int a[n + 1];
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int alice = a[1];
  int t = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] <= a[1] / 2) {
      t++;
      alice += a[i];
    }
  }
  if (alice >= sum / 2) {
    cout << t << endl;
    cout << 1 << " ";
    for (int i = 2; i <= n; i++) {
      if (a[i] <= a[1] / 2) cout << i << " ";
    }
    return 0;
  }
  cout << 0;
}
