#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int val = 8 * n + 1;
  int root = sqrt(val);
  int ans = 0;
  if (root * root == val) {
    if (root % 2 == 1) {
      ans = 1;
    }
  }
  if (ans == 0) {
    cout << "NO";
  } else {
    cout << "Yes";
  }
  return 0;
}
