#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int main() {
  int n;
  cin >> n;
  int i, k = 0;
  vector<int> a;
  int j;
  for (i = 0; i < n; i++) {
    cin >> j;
    a.push_back(j);
  }
  for (i = 1; i < a.size(); i++) {
    if (gcd(a[i], a[i - 1]) != 1) {
      a.insert(a.begin() + i, a[i] - 1);
      k++;
    }
  }
  cout << k << endl;
  for (i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  return 0;
}
