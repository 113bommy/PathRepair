#include <bits/stdc++.h>
using namespace std;
int a[1000005], i, n, ans = 1, lol = 1;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (i = 2; i <= n; i++) {
    if (a[i] > a[i - 1]) {
      ans++;
    } else {
      ans = 1;
    }
    lol = max(lol, ans);
  }
  cout << lol;
}
