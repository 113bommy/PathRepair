#include <bits/stdc++.h>
using namespace std;
int the_10_sum(int n) {
  int sum = 0;
  while (n) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main() {
  int n;
  cin >> n;
  int k = 0, a[100001] = {0};
  for (int i = 19; i < 0xffffff; i++) {
    if (the_10_sum(i) == 10) {
      a[k] = i;
      ++k;
    }
  }
  cout << a[n - 1];
  return 0;
}
