#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0;
  cin >> n;
  int diff;
  for (int i = 1; i <= 500; i++) {
    sum += i;
    if (sum == n) {
      diff = 0;
      break;
    }
  }
  if (diff == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
