#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, i, j;
  cin >> n;
  int a[n + 1];
  a[0] = 0;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a, a + n + 1);
  if (n % 2 == 0) {
    for (i = 2, j = n - 1; i <= n / 2; i = i + 2, j = j - 2) {
      swap(a[i], a[j]);
    }
  } else {
    for (i = 2, j = n; i < j; i = i + 2, j = j - 2) {
      swap(a[i], a[j]);
    }
  }
  for (i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
