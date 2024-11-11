#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int a[n + 5];
  a[1] = 1;
  a[2] = 2;
  for (int i = 3; i <= n; ++i) {
    a[i] = a[i - 2] + i;
  }
  cout << a[n] << endl;
  return 0;
}
