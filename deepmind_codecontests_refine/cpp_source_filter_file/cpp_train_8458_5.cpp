#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 1];
    for (long long i = 1; i <= n; i++) a[i] = 0;
    long long b[n];
    for (int i = 0; i < 2 * n; i++) {
      cin >> b[i];
      a[b[i]]++;
      if (a[b[i]] == 1) cout << b[i] << " ";
    }
    cout << endl;
  }
}
