#include <bits/stdc++.h>
using namespace std;
int arr[1000];
int main() {
  int o = 0, e = 0, n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x % 2 == 0)
      e++;
    else
      o++;
  }
  if (o % 2 == 1)
    cout << max(o, e);
  else
    cout << e;
  return 0;
}
