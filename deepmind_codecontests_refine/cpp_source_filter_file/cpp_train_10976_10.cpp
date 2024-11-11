#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a, res = 0;
  cin >> n >> k;
  while (n > 0) {
    cin >> a;
    if (5 - a > k) res++;
    n--;
  }
  cout << res / 3;
  return 0;
}
