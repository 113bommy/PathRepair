#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cm = 0;
  int i = 0;
  while (i < n) {
    int minp = -1;
    int minv = 10000;
    for (int j = 0; j < n; j++) {
      if (a[j] > cm && a[j] < minv) {
        minv = a[j];
        minp = j;
      }
    }
    if (minp == -1) {
      cm = 0;
    } else {
      int t = a[minp];
      a[minp] = a[i];
      a[i] = t;
      cm = a[i];
      i++;
    }
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] < a[i]) {
      ans++;
    }
  }
  cout << ans;
  cout << endl;
  return 0;
}
