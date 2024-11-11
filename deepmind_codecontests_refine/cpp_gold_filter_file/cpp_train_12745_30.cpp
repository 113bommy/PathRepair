#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, k;
  cin >> n >> p >> k;
  if (p - k > 1) cout << "<< ";
  for (int i = p - k; i <= p + k; i++) {
    if (i <= n && i == p) {
      cout << '(' << i << ") ";
      continue;
    }
    if (i <= n && i > 0) cout << i << " ";
  }
  if (p + k < n) cout << ">>";
  return 0;
}
