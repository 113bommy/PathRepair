#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[101];
  a[0] = 0;
  a[1] = 1;
  for (int i = 2; i <= n; i++) {
    a[i] = a[i - 1] + 4 * i - 4;
  }
  cout << a[n] << endl;
}
