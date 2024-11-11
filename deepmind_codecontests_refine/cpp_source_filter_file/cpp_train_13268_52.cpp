#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, q, i = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p >> q;
    if (p < q) i++;
  }
  cout << i;
  return 0;
}
