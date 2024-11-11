#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, r = 1;
  cin >> n >> m;
  if (n > m) {
    cout << 0;
  } else {
    long long a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int j = 0; j < i; j++) {
        int t = abs(a[i] - a[j]) % m;
        r = r * t % m;
      }
    }
    cout << r;
  }
}
