#include <bits/stdc++.h>
using namespace std;
char ans[1000003];
int coun;
int n;
int a[203];
int main() {
  cin >> n;
  int i;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) {
    while (a[i] > 0) {
      a[i]--;
      ans[coun++] = 'P';
      if (a[i] > 0) {
        if (i != n - 1) {
          ans[coun++] = 'R';
          ans[coun++] = 'L';
        } else {
          ans[coun++] = 'L';
          ans[coun++] = 'R';
        }
      }
    }
    if (i != n - 1) ans[coun++] = 'R';
  }
  cout << ans << endl;
  return 0;
}
