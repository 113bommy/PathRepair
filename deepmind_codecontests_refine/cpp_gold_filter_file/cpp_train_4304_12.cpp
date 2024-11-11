#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[18258];
  a[0] = 1;
  a[1] = 12;
  a[2] = 24;
  int i;
  for (i = 3; i < 18257; i++) a[i] = a[i - 1] + 12;
  while (cin >> n) {
    long long sum = 0;
    for (i = 0; i < n; i++) sum += a[i];
    cout << sum << endl;
  }
  return 0;
}
