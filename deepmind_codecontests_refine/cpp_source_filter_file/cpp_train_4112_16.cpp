#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 0, num, e = 1;
  cin >> n;
  num = n;
  if (n < 10)
    count = n;
  else {
    while (num) {
      num /= 10;
      ++count;
    }
    num = count;
    count = 0;
    for (int i = 1; i < num; i++) {
      count += 9 * e * i;
      n -= (9 * e);
      e *= 10;
    }
    count += n * num;
  }
  cout << count;
  return 0;
}
