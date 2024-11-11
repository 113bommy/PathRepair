#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n + 1], mx = 0, in;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (mx < a[i]) {
      in = i;
      mx = a[i];
    }
  }
  sort(a + 1, a + n + 1);
  cout << in << " " << a[n - 1];
  return 0;
}
