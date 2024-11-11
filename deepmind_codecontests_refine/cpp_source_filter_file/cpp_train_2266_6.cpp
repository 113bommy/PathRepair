#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, j;
  cin >> n;
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 2, j; i < 2 * n; i += 2) {
    for (j = i; j < 2 * n; j++) {
      if (a[j] == a[i - 1]) break;
    }
    for (; j > i; j--) {
      swap(a[j], a[j - 1]);
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
