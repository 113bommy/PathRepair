#include <bits/stdc++.h>
using namespace std;
void tim(long long s, long long p) {
  double d = s * s - 4 * p;
  cout << "YES"
       << " ";
  cout << setprecision(9) << fixed << (s * 1.0 + (double)sqrt(d)) / (2 * 1.0)
       << " ";
  cout << setprecision(9) << fixed << (s * 1.0 - (double)sqrt(d)) / (2 * 1.0)
       << endl;
}
int main() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long z = 1; z <= n; z++) {
    if (a[z] * a[z] - 4 * a[z] < 0)
      cout << "N" << endl;
    else {
      long long s = a[z];
      long long p = a[z];
      tim(s, p);
    }
  }
}
