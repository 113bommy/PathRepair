#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  ;
  vector<long long int> a(n);
  for (long long int i = 0; i < n; i++) cin >> a[i];
  ;
  long long int tf = 0, f = 0, h = 0;
  for (long long int i = 0; i < n; i++) {
    if (a[i] == 25)
      tf++;
    else {
      long long int ch = a[i] - 25;
      if (ch == 25) {
        if (tf > 0)
          tf--;
        else {
          cout << "NO\n";
          return 0;
        }
      } else if (ch == 75) {
        if (f > 0 && tf > 0) {
          f--;
          tf--;
        } else if (tf > 3) {
          tf -= 3;
        } else {
          cout << "NO\n";
          return 0;
        }
      }
    }
    if (a[i] == 50)
      f++;
    else if (a[i] == 100)
      h++;
  }
  cout << "YES\n";
  return 0;
}
