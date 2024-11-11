#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, s, suma = 0, sum = 0, i;
    cin >> n >> s;
    long long a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum <= s)
      cout << "0"
           << "\n";
    else {
      i = 0;
      long long max = 0, index = 0;
      while (suma + a[i] <= s) {
        suma += a[i];
        if (a[i] >= max) {
          max = a[i];
          index = i;
        }
        i++;
      }
      if (a[index] >= a[i])
        cout << index + 1 << "\n";
      else
        cout << i + 1 << "\n";
    }
  }
  return 0;
}
