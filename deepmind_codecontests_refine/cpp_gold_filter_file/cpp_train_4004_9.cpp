#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, s = 0, p, n = 0, arr[1000];
  cin >> a >> b >> c;
  for (int i = 1; i <= 81; i++) {
    p = i;
    s = 0;
    for (int j = 1; j < a; j++) p *= i;
    p *= b;
    p += c;
    long long int d = p;
    while (d > 0) {
      s = s + (d % 10);
      d /= 10;
    }
    if (s == i && p > 0 && p < 1e9) {
      arr[n] = p;
      n++;
    }
  }
  cout << n << "\n";
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  return 0;
}
