#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x[250505] = {0};
  int m = -1;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    x[t]++;
    m = max(t, m);
  }
  int sum = 0;
  for (int i = 0; i < m; i++) {
    if (x[i] == 0) continue;
    sum += (x[i] - 1);
  }
  if (x[0] != 0) sum++;
  cout << sum;
}
