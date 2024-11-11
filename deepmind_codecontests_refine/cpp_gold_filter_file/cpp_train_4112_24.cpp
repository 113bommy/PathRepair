#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x;
  cin >> x;
  long long n;
  long long sum = 0;
  long long count = 1;
  long long counter = 1;
  while (true) {
    n = 9 * counter;
    counter *= 10;
    if (x > n) {
      x -= n;
      sum += n * count;
    } else {
      sum += x * count;
      break;
    }
    count++;
  }
  cout << sum << endl;
  return 0;
}
