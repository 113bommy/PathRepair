#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = n + 1; i < 9001; i++) {
    vector<bool> v(10, 0);
    int k = i;
    while (k != 0) {
      v[k % 10] = !v[k % 10];
      if (!v[k % 10]) break;
      k /= 10;
    }
    if (!k) {
      cout << i;
      return 0;
    }
  }
}
