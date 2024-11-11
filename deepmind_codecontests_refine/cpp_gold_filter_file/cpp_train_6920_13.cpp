#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m;
  cout << min(min(n, m), (n + m) / 3);
  return 0;
}
