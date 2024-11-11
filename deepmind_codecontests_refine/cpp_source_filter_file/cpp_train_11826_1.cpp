#include <bits/stdc++.h>
using namespace std;
int main() {
  long n;
  cin >> n;
  long a[n];
  for (long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long mi = 1000000000, count = 0;
  for (long i = 0; i < n - 1; i++) {
    long s = abs(a[i] - a[i + 1]);
    if (s < mi) {
      mi = s;
      count = 1;
    } else if (s == mi) {
      count++;
    }
  }
  cout << mi << " " << count << endl;
}
