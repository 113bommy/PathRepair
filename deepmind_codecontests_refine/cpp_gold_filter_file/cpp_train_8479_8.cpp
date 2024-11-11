#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  int i = 1, j = n;
  cout << i++ << " ";
  if (k == 1) {
    while (i <= j) cout << i++ << " ";
    return 0;
  }
  while (k > 2) {
    cout << j-- << " " << i++ << " ";
    k -= 2;
  }
  if (k > 1) {
    while (j >= i) cout << j-- << " ";
  } else {
    while (i <= j) cout << i++ << " ";
  }
  cout << endl;
}
