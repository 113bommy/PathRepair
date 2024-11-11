#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  (n >= 29) ? printf("%d\n", m) : printf("%d\n", m % (int)pow(2, n));
  return 0;
}
