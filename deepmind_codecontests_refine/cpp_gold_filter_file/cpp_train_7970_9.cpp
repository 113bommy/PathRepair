#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i = 0;
  cin >> n >> k;
  k = 240 - k;
  while (k > 0) {
    i++;
    k -= 5 * i;
    if (i == n) break;
  }
  if (k < 0) {
    i--;
  }
  cout << i;
}
