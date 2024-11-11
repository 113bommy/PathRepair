#include <bits/stdc++.h>
using namespace std;
long long int f[1002];
int main() {
  long long int k;
  cin >> k;
  while (k--) {
    long long int n;
    for (long long int i = 0; i < 1002; i++) f[i] = 0;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      f[a[i]]++;
    }
    for (long long int i = 1000; i >= 0; i--) {
      f[i] += f[i + 1];
      if (f[i] >= i) {
        cout << i << "\n";
        break;
      }
    }
  }
  return 0;
}
