#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int sm = 0;
  int mx = INT_MIN;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mx = max(mx, x);
    sm += x;
  }
  int val = ceil((float)(sm + m) / (float)n);
  cout << max(val, mx) << " " << mx + m << endl;
  return 0;
}
