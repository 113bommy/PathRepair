#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  cin >> n >> k;
  k = 241 - k;
  n++;
  while (n--)
    if (k - (5 * n * (n + 1) / 2) >= 0) break;
  cout << n;
  return 0;
}
