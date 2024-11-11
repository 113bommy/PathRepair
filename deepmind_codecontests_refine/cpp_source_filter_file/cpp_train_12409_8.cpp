#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, r;
  cin >> l >> r;
  while (l != r) {
    int arr[9] = {0};
    int x = l;
    bool diff = 1;
    while (x) {
      int num = x % 10;
      x /= 10;
      if (arr[num]) {
        diff = 0;
        l++;
        break;
      }
      arr[num]++;
    }
    if (diff) {
      cout << l << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
