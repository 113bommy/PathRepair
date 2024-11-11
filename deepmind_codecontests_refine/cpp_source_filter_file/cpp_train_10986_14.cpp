#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> ok(n);
  for (int i = 0; i < n; i++) cin >> ok[i];
  if (n == 1 || n == 2 || n == 3) {
    cout << n;
    exit(0);
  }
  int maxi = INT32_MIN;
  for (int i = 0; i < n; i++) {
    int ctr = 1;
    int j;
    for (j = i + 1; j < n; j++)
      if (ok[i] >= ok[i - 1])
        ctr++;
      else
        break;
    for (; j < n; j++)
      if (ok[i] <= ok[i - 1])
        ctr++;
      else
        break;
    maxi = max(ctr, maxi);
  }
  cout << maxi;
}
