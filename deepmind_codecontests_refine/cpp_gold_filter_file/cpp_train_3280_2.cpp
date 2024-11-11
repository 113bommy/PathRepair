#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int MIN = INT_MAX;
  int sum(0);
  while (n--) {
    int tmp;
    cin >> tmp;
    sum = sum + tmp;
    if (tmp % 2 == 1 && tmp < MIN) {
      MIN = tmp;
    }
  }
  if (sum % 2 == 1) {
    cout << sum << endl;
  } else {
    if (MIN == INT_MAX) {
      cout << 0 << endl;
    } else {
      cout << sum - MIN << endl;
    }
  }
}
