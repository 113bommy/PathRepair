#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (auto &e : h) cin >> e;
  sort(begin(h), end(h));
  int r = 1e9;
  for (int i = 0; i + k - 1 < n; i++) r = max(r, h[i + k - 1] - h[i]);
  cout << r << endl;
}
