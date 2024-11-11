#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n, aCount, bCount, input;
int main() {
  cin >> n;
  a.resize(n);
  for (size_t i = 0; i < n; i++) cin >> a[i];
  for (size_t i = 0; i < n; i++) {
    cin >> input;
    if (!input && a[i])
      ++aCount;
    else if (input && !a[i])
      ++bCount;
  }
  if (!aCount)
    cout << -1;
  else if (bCount == 0)
    cout << 1;
  else {
    cout << (bCount + aCount) / aCount;
  }
  return 0;
}
