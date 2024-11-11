#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n = 0, counter = 0, sum = 0, length;
  string z;
  cin >> z;
  length = z.length();
  if (length > 1) {
    for (int i = 0; i < length; i++) {
      n += z[i] - '0';
    }
    counter++;
    while (n / 10 != 0) {
      counter++;
      sum = 0;
      while (n > 0) {
        sum += n % 10;
        n = n / 10;
      }
      n = sum;
    }
  }
  cout << counter;
  return 0;
}
