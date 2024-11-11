#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, q, j = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p >> q;
    if (p < (q - 1)) j++;
  }
  cout << j;
  return 0;
}
