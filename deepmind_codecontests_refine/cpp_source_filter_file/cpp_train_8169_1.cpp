#include <bits/stdc++.h>
using namespace std;
long long int ABS(long long int a) {
  if (a < 0) return (-a);
  return a;
}
int a[100002];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, j = 0;
  cin >> (n);
  for (int i = (0); i < (n); ++i) cin >> (a[i]);
  if (a[n - 1] == 1)
    cout << "NO" << endl;
  else {
    if (n == 1 and a[0] == 0)
      cout << "YES\n0" << endl;
    else {
      int i = n - 3;
      while (i >= 0 and a[i] == 1) i--;
      if (i == -1 and a[n - 1] == 0 and a[n - 2] == 0)
        cout << "NO" << endl;
      else {
        if (a[n - 2] == 1) {
          cout << "YES" << endl;
          cout << a[0];
          for (int i = (1); i < (n); ++i) cout << "->" << a[i];
        } else {
          int j = n - 3, flg = 1;
          while (a[j] == 1) {
            j--;
            flg = 0;
          }
          cout << "YES" << endl;
          for (int i = (0); i < (n - 1); ++i) {
            if (i == j or (i == j - 1 and flg == 0)) cout << "(";
            cout << a[i];
            if (i == n - 2) {
              cout << ")";
              if (flg == 0) cout << ")";
            }
            cout << "->";
          }
          cout << a[n - 1] << endl;
        }
      }
    }
  }
  return 0;
}
