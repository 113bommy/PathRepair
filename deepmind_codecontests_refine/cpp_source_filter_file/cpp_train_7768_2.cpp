#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[100002], n, l, amt;
  amt = 0;
  cin >> n >> l;
  for (int x = 0; x < n; x++) {
    cin >> a[x];
    amt = amt + a[x];
  }
  if (amt + n - 1 <= l) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
