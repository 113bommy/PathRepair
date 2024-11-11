#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main() {
  int n;
  while (cin >> n, n) {
  int up = 0;
  int low = 100000;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < 5; j++) {
      int a;
      cin >> a;
      sum += a;
    }
    up = max(up, sum);
    low = min(low, sum);
  }
  cout << up << " " << low << endl;
}
  return 0;
}