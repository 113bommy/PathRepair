#include <bits/stdc++.h>
using namespace std;
int main() {
  int s = 0, n;
  cin >> n;
  int a[n], i;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i] * i;
  }
  cout << s;
  return 0;
}
