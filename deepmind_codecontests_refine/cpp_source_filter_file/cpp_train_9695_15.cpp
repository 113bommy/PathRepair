#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[101], cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i += 2) cnt += a[i] - a[i - 1];
  cout << cnt << endl;
  return 0;
}
