#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string a[n];
  int i;
  int j;
  for (i = 0; i != n; i++) {
    cin >> a[i];
  }
  for (i = 0; i != n; i++) {
    int o = 1;
    for (j = 0; j != i; j++)
      if (a[i] == a[j]) {
        cout << "YES" << endl;
        o = 0;
        break;
      }
    if (o == 1) cout << "NO" << endl;
  }
}
