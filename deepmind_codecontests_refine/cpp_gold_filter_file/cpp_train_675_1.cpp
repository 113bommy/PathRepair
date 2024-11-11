#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int k;
  bool flag = true;
  int cur;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    k = 0;
    for (int j = 0; j < n; ++j) {
      cin >> cur;
      k = max(k, cur);
    }
    if (k == n - 1 && flag) {
      k++;
      flag = false;
    }
    cout << k << " ";
  }
  return 0;
}
