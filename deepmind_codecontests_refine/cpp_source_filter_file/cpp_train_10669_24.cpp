#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[2000] = {0};
  int x[2001] = {0};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    x[a[i]]++;
  }
  int c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = a[i] + 1; j < 2001; j++) {
      if (j != 2001) {
        c += x[j];
      }
    }
    cout << c + 1;
    c = 0;
  }
  return 0;
}
