#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<long long> h(n);
  for (int i = 0; i < n; i++) cin >> h[i];
  sort(h.begin(), h.end());
  cout << abs(h[b] - h[b - 1]) << endl;
  return 0;
}
