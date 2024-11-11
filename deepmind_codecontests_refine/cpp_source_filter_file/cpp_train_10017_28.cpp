#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  int t, x, c = 0, c2 = 0;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> x;
    c += x;
    v.push_back(x);
  }
  for (int i = 0; i < t; i++) {
    if (c - v[i] % 2 == 0) c2++;
  }
  cout << c2;
  return 0;
}
