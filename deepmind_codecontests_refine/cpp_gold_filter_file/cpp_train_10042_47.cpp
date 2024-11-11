#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0;
  cin >> n;
  int diff = 0;
  for (int i = 1; i <= 500; i++) {
    sum += i;
    if (sum == n) {
      diff = 1;
      break;
    }
  }
  if (diff == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
