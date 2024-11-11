#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, sum = 0, a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long x, y;
    cin >> x >> y;
    sum += y;
  }
  a = sum / n + 5;
  cout << a;
  return 0;
}
