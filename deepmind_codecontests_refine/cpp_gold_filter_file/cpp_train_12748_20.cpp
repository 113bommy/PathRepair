#include <bits/stdc++.h>
using namespace std;
const int maxx = 1e2 + 7;
int n, a[maxx];
int main() {
  cin >> n;
  a[0] = 0;
  a[1] = 1;
  a[2] = 2;
  for (int i = 3; i <= n; i++) {
    if (a[i - 1] + i - 1 <= n)
      a[i] = a[i - 1] + i - 1;
    else
      a[i] = a[i - 1] + i - 1 - n;
  }
  for (int i = 2; i <= n; i++) cout << a[i] << " ";
  cout << endl;
}
