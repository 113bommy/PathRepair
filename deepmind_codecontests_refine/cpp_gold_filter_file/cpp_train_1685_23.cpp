#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int temp = t;
  int* ans1 = new int[t];
  while (t--) {
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    int min = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] <= min || min == -1) {
        min = a[i];
        continue;
      } else
        ans++;
    }
    ans1[t] = ans;
  }
  for (int i = temp - 1; i >= 0; i--) cout << ans1[i] << endl;
  return 0;
}
