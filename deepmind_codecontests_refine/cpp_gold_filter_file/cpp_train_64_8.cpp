#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  vector<int> b;
  for (i = 0; i < n; i++) {
    if (a[i] <= 1e6 - a[i])
      b.push_back(a[i] - 1);
    else
      b.push_back(1e6 - a[i]);
  }
  sort(b.begin(), b.end());
  cout << b[b.size() - 1];
}
