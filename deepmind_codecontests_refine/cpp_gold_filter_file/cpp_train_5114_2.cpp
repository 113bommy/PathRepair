#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, c = 0;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 1; i < n - 1; i++) {
    if (a[i - 1] == 1 && a[i] == 0 && a[i + 1] == 1) {
      c++;
      i += 2;
    }
  }
  cout << c;
}
