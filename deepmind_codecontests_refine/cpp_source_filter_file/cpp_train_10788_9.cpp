#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int left = 0;
  int right = 0;
  while (n--) {
    int a, b;
    cin >> a >> b;
    if (a < 0) {
      left++;
    } else {
      right++;
    }
  }
  if ((left > 1 && right == 1) || (right > 1 && left == 1) || left == 0 ||
      right == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
