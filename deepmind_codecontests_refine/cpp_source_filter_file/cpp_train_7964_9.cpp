#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;
    a[x] = i;
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans += abs(a[i] - a[i - 1]);
  }
  cout << ans;
  return 0;
}
