#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n > 1) sort(a, a + n);
  int cont = 0;
  if (k == n) {
    cout << a[k - 1] << "\n";
  } else if (k == 0) {
    if (a[0] - 1 >= 1)
      cout << a[0] - 1 << endl;
    else
      puts("-1");
  } else {
    k--;
    if (a[k] == a[k + 1])
      cout << -1 << endl;
    else
      cout << a[k] + 1 << endl;
  }
}
