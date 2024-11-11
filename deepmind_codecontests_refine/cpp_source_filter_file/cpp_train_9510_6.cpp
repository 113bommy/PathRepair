#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], i;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  int min = a[0], x, c = 0;
  for (i = 0; i < n; i++) {
    if (min > a[i]) {
      min = a[i];
      x = i;
    }
  }
  for (i = 0; i < n; i++)
    if (min == a[i]) c++;
  if (c == 1)
    cout << x + 1;
  else {
    cout << "Still Rozdil";
  }
  return 0;
}
