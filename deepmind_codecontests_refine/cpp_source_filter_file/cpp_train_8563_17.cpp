#include <bits/stdc++.h>
using namespace std;
int GCD(int a, int b) { return (!b ? a : GCD(b, a % b)); }
int main(void) {
  int A;
  cin >> A;
  int sum = 0;
  int count;
  for (int i = 2; i < A; i++) {
    int x = A;
    while (x) {
      sum += x % i;
      x = x / i;
    }
  }
  count = GCD(sum, A - 2);
  cout << sum / count << "/" << A - 2 / count << endl;
  return 0;
}
