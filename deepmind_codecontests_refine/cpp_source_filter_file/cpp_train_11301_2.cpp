#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int l1, r1, l2, r2, k;
  cin >> l1 >> r1 >> l2 >> r2 >> k;
  long long int ans = min(r1, r2) - max(l1, l2) + 1;
  if (k >= min(r1, r2) && k <= max(l1, l2)) ans--;
  cout << max(ans, 0ll);
  return 0;
}
