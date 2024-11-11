#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> vc(n);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  sort(vc.begin(), vc.end());
  auto prit = vc.begin() + n / 2;
  int i;
  for (i = 0; i < n / 2; i++) {
    auto it = lower_bound(prit, vc.end(), 2 * vc[i]);
    if (it == vc.end()) {
      break;
    } else {
      prit = it + 1;
    }
  }
  cout << n - i << endl;
}
