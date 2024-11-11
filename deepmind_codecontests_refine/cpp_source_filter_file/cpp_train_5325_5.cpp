#include <bits/stdc++.h>
using namespace std;
int n, a[1000001], d, b[1000], minn = 10000;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[a[i]]++;
    minn = min(minn, a[i]);
  }
  if (b[minn] > 1)
    cout << "Bob";
  else
    cout << "Alice";
  return 0;
}
