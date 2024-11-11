#include <bits/stdc++.h>
using namespace std;
vector<int> h;
int main() {
  int n, a, b, x;
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> x;
    h.push_back(x);
  }
  sort(h.begin(), h.end());
  cout << h[b] - h[b - 1];
  return 0;
}
