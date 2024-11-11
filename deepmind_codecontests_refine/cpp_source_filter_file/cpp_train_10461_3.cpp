#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, w;
  int x;
  cin >> k >> n >> w;
  for (int j = 1; j <= w; j++) x = x + j * k;
  if (x > n)
    cout << x - n;
  else
    cout << 0;
  return 0;
}
