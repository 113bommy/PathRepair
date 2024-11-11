#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[105], n;
  cin >> n;
  for (int i = 1, j; i <= n; i++) {
    cin >> j;
    a[i] = j;
  }
  for (int i = 1; i <= n - 1; i++) cout << a[i] << ' ';
  cout << a[n];
  return 0;
}
