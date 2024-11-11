#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, cnt = 0;
  cin >> n >> a;
  if (a % 2 == 0) {
    if (n == a) {
      cout << "1" << endl;
    } else {
      for (int i = n; i >= a; i -= 2) {
        cnt++;
      }
      cout << cnt << endl;
    }
  } else {
    cout << (a / 2) + 1 << endl;
  }
  return 0;
}
