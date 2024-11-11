#include <bits/stdc++.h>
using namespace std;
int k;
int main() {
  int i, t;
  cin >> k;
  cout << "2000\n-1 ";
  k += 2000;
  for (i = 1; i <= 2000; i++) {
    t = min(k, 1000000);
    printf("%d ", t);
    k -= t;
  }
  return 0;
}
