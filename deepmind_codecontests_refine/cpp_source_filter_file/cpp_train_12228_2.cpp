#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, a, b;
  cin >> n >> a >> b;
  long long s = n * 6;
  if (a * b >= s) {
    cout << a * b << endl;
    cout << a << " " << b << endl;
    return 0;
  }
  for (long long i = s; i; i++) {
    for (int j = a; j <= sqrt(i); j++)
      if (i % j == 0 && i / j >= b) {
        cout << i << endl;
        cout << j << " " << i / j << endl;
        return 0;
      }
    for (int j = b; j <= sqrt(i); j++)
      if (i % j == 0 && i / j >= a) {
        cout << i << endl;
        cout << j << " " << i / j << endl;
        return 0;
      }
  }
  return 0;
}
