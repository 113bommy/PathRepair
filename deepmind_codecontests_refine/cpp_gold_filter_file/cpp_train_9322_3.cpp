#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  int q;
  cin >> q;
  while (q--) {
    int price;
    cin >> price;
    auto it = upper_bound(v.begin(), v.end(), price);
    if (it == v.begin() && !binary_search(v.begin(), v.end(), price))
      cout << '0' << '\n';
    else
      cout << it - v.begin() << '\n';
  }
  return 0;
}
