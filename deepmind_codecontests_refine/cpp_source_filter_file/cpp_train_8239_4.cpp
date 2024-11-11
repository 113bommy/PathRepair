#include <bits/stdc++.h>
using namespace std;
int n, x, k, s;
vector<int> v;
int main() {
  cin >> n;
  cin >> x;
  k = x;
  v.push_back(1);
  for (int i = 1; i < n; i++) {
    cin >> x;
    if ((x + x) <= k) {
      k += x;
      v.push_back(i + 1);
    } else {
      s += x;
    }
  }
  if (k <= s) {
    cout << 0;
  } else {
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
  }
  return 0;
}
