#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, a, sum;
  cin >> n >> x;
  while (n--) {
    cin >> a;
    sum += a;
  }
  cout << ceil((double)(abs(sum)) / x) << endl;
  return 0;
}
