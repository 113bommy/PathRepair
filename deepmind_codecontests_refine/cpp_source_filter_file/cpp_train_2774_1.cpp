#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, l = 0, j, p, m;
  long k;
  cin >> n >> k;
  long long a[k];
  for (long i = 0; i < k; i++) {
    cin >> a[i];
    j = n / a[i];
    if ((j * a[i]) > l) {
      l = j * a[i];
      p = i + 1;
      m = j;
    }
  }
  cout << p << " " << m << endl;
  return 0;
}
