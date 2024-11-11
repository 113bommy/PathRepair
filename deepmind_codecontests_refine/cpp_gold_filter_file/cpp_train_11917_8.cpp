#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  int i = 2, res = 1, counter = 0, sum = 1;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  while (sum <= n) {
    res = res + i;
    sum = sum + res;
    i++;
    counter++;
  }
  cout << counter;
}
