#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    int k = l;
    int j = (k)*2;
    if (j < r) cout << k << " " << j << endl;
    if (j >= r)
      cout << "-1"
           << " "
           << "-1" << endl;
  }
}
