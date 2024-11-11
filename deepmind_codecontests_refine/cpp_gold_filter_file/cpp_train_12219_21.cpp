#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n;
  cin >> n;
  long int a[n];
  for (long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long int c = 0, b = 0, ba = 0;
  for (long int i = 0; i < n; i += 3) {
    c += a[i];
    if (i + 1 < n) b += a[i + 1];
    if (i + 2 < n) ba += a[i + 2];
  }
  if (c > b && c > ba) cout << "chest" << endl;
  if (b > c && b > ba) cout << "biceps" << endl;
  if (ba > b && ba > c) cout << "back" << endl;
  return 0;
}
