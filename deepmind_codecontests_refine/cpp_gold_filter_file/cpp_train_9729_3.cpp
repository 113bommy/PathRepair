#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    if (i % m == 0) n++;
  }
  cout << i - 1;
  return 0;
}
