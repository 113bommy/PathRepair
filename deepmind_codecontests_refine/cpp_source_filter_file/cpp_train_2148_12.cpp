#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, mn = 10000000, mni = 0, i, a;
  cin >> n;
  vector<long int> g(200001, 0);
  for (i = 1; i <= n; i++) {
    cin >> a;
    g[a] = i;
  }
  for (i = 1; i < 200001; i++) {
    if (g[i] > 0 && g[i] < mn) {
      mn = g[i];
      mni = i;
    }
  }
  cout << mni;
  return 0;
}
