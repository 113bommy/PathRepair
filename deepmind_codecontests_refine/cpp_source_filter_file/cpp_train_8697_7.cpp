#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int win, loos, temp, first = 1, second = 2, i, n, a;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    if ((a - 1) % 2 != 0) {
      win = first;
    } else {
      win = second;
    }
    if (win == first) {
      temp = first;
      first = second;
      second = temp;
    }
    cout << win;
  }
  return 0;
}
