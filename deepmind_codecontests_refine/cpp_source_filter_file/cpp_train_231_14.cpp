#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, cnt = 0;
    cin >> n;
    while (n > 1) {
      if (n % 6 == 0) {
        n = n / 6;
        cnt++;
      } else {
        n = n * 2;
        cnt++;
        if (n % 6 == 0) {
          n = n / 6;
          cnt++;
        } else {
          cout << "-1" << endl;
          break;
        }
      }
    }
    if (n == 1) {
      cout << "cnt" << endl;
    }
  }
  return 0;
}
