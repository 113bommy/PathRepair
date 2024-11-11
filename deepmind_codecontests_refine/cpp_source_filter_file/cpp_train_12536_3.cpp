#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a[100000], k = 0;
  cin >> n;
  for (long long int i = 0; i < n; i++) cin >> a[i];
  long long int z = 0, c = 0;
  long long int zer[100000];
  for (long long int i = n - 1; i >= 0; i--) {
    if (a[i] == 1) {
      zer[k++] = z;
    } else
      z++;
  }
  for (long long int i = 0; i < k; i++) {
    c += zer[i];
  }
  cout << c;
  return 0;
}
