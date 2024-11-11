#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int maxx = -1;
  long long int n;
  long long int a[100011];
  cin >> n;
  long long int l = 0;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i - 2] + a[i - 1] == a[i] && i > 2)
      l++;
    else {
      if (i > 2)
        if (l > maxx) maxx = l;
      l = 0;
    }
  }
  if (maxx < l)
    cout << l + 2;
  else
    cout << maxx + 2;
  return 0;
}
