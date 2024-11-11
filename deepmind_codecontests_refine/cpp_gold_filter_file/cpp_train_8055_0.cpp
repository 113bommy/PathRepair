#include <bits/stdc++.h>
using namespace std;
long n, a1, b1, k, a[123456], b[123456];
int main() {
  cin >> a1 >> b1 >> k;
  for (long i = 0; i < a1; i++) cin >> a[i];
  for (long i = 0; i < b1; i++) cin >> b[i];
  sort(a, a + a1);
  sort(b, b + b1);
  if (a1 > b1) {
    cout << "YES";
    return 0;
  }
  long j = b1 - 1;
  for (long i = a1 - 1; i >= 0; i--) {
    if (a[i] > b[j]) {
      cout << "YES";
      return 0;
    }
    j--;
  }
  cout << "NO";
  return 0;
}
