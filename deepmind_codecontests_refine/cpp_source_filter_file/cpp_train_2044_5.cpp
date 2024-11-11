#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, j = 0, k;
  cin >> n;
  cout << ((n * (n + 1)) / 2) % 2 << endl;
  cout << n / 2 << " ";
  k = n;
  for (int i = 0; i < n / 2; i++) {
    cout << k - j << " ";
    k -= 2;
    j = !j;
  }
  return 0;
}
