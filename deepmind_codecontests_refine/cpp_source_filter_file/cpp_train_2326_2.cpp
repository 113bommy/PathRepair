#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int d, n, i, sum = 0;
  int a[1000000];
  cin >> d >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (i != n) {
      sum = sum + (d - a[i]);
    }
  }
  cout << sum << endl;
  return 0;
}
