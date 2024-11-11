#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n], o = 0, e = 0;
    for (long long int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 0) {
        e++;
      } else {
        o++;
      }
    }
    if (e == 0 && o < 2) {
      cout << "-1\n";
    } else {
      if (e > 0) {
        for (long long int i = 1; i <= n; i++) {
          if (a[i] % 2 == 0) {
            cout << "1\n" << i << '\n';
            break;
          }
        }
      } else {
        cout << "2\n";
        for (long long int i = 1, j = 0; j < 2; i++) {
          if (a[i] % 2 != 0) {
            cout << i << " ";
            j++;
          }
        }
        cout << '\n';
      }
    }
  }
  return 0;
}
