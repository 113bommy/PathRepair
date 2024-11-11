#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, idx, ans = 1;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) idx = i;
  }
  for (int i = idx; i < n - 1; i++) {
    if (a[i] > a[i] + 1)
      ans = 1;
    else
      ans++;
  }
  cout << n - ans;
  return 0;
}
