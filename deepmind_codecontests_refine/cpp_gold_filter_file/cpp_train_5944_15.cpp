#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i;
  long long a[1010];
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (cin >> n) {
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (!(a[i] % 2)) a[i] -= 1;
    }
    for (i = 0; i < n; i++) cout << a[i] << ' ';
    cout << endl;
  }
  return 0;
}
