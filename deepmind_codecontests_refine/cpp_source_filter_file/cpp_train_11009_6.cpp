#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 0;
  cin >> n;
  if (n > 100) {
    count = n / 100;
    n %= 100;
  }
  if (n > 20) {
    count += n / 20;
    n %= 20;
  }
  if (n > 10) {
    count += n / 10;
    n %= 10;
  }
  if (n > 5) {
    count += n / 5;
    n %= 5;
  }
  if (n < 5) {
    count += n;
  }
  cout << count;
}
