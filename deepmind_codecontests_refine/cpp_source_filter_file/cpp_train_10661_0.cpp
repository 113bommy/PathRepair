#include <bits/stdc++.h>
using namespace std;
int ar[1000007];
int main() {
  int i, j, n, k, a, b;
  cin >> n >> k;
  if (k >= (n - 1))
    cout << "-1" << endl;
  else {
    a = n - k;
    for (i = 1; i < a; i++) cout << i + 1 << " ";
    cout << 1 << " ";
    for (i++; i <= n; i++) cout << i << " ";
    cout << endl;
  }
  return 0;
}
