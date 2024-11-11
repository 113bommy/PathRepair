#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[100005] = {0};
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int l = 1, r = n;
  while (l < n && a[l + 1] == a[l]) {
    l++;
  }
  while (r > 1 && a[r - 1] == a[r]) {
    r--;
  }
  cout << (r - l - 1 > 0) ? (r - l - 1) : 0;
  return 0;
}
