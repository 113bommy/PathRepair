#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a;
  vector<int> v;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  cout << v[(n - 1) / 2];
  return 0;
}
