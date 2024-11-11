#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int r = *(std::min_element(a.begin(), a.end()));
  if (r == 1) {
    r = 0;
  } else {
    r = 1;
  }
  cout << r;
  return 0;
}
