#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int num, ans, temp;
  int a[101];
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  num = a[n - 1];
  sort(a + 1, a + n + 1);
  temp = a[n - 1];
  ans = num ^ temp;
  cout << ans << endl;
  return 0;
}
