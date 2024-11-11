#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int b[100];
  for (int i = 0; i < 100; i++) b[i] = 0;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    b[x - 1] += 1;
  }
  x = b[0];
  for (int i = 0; i < 100; i++) {
    if (b[i] > x) {
      x = b[i];
    }
  }
  if (x % k == 0)
    x = x / k;
  else
    x = x / k + 1;
  x = x * k;
  k = 0;
  for (int i = 0; i < 100; i++)
    if (b[i]) {
      k += x - b[i];
    }
  cout << k;
  return 0;
}
