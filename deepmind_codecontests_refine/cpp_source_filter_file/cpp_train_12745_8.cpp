#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, p;
  cin >> n >> k >> p;
  if (k - p > 0) cout << "<< ";
  for (int i = max(1, k - p); i <= min(n, k + p); i++) {
    if (i == k)
      cout << "(" << k << ")"
           << " ";
    else
      cout << i << " ";
  }
  if (n > k + p) cout << ">>";
  return 0;
}
