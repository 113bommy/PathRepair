#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, kq = 0;
  int value;
  cin >> n;
  cin >> h;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> value;
    v.push_back(value);
  }
  for (int i = 0; i < n; i++) {
    if (v[i] > h)
      kq = kq + 2;
    else if (v[i] <= h)
      kq = kq + 1;
  }
  cout << kq;
  return 0;
}
