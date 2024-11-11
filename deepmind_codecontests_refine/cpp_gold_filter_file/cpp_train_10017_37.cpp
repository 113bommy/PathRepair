#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a, cnte = 0, cnto = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if (a % 2)
      cnto++;
    else
      cnte++;
  }
  if (cnto % 2)
    cout << cnto;
  else
    cout << cnte;
  return 0;
}
