#include <bits/stdc++.h>
using namespace std;
long unsigned retATranssf(long unsigned a) {
  vector<long unsigned> arr(0);
  while (a > 0) {
    if (a % 10 == 4 || a % 10 == 7) {
      arr.push_back(a % 10);
    }
    a /= 10;
  }
  long unsigned ret = 0;
  for (long unsigned i = 0; i < arr.size(); i++) {
    ret += arr[i] * pow(10.0, (double)i);
  }
  return ret;
}
int main(int argv, char* argc[]) {
  long unsigned a = 0, b = 0;
  cin >> a >> b;
  for (long unsigned i = a; i <= pow(10.0, 8.0); i++) {
    if (retATranssf(i) == b) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
