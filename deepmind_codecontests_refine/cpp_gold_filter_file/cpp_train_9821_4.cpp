#include <bits/stdc++.h>
using namespace std;
int a[110], k;
int main() {
  cin >> a[0] >> a[1] >> k;
  for (int i = 2; i <= k; i++) a[i] = a[i - 1] + a[i - 2];
  cout << a[k] << endl;
  return 0;
}
