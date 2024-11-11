#include <bits/stdc++.h>
using namespace std;
vector<long long> fibo;
int main() {
  long long x;
  cin >> x;
  if (x == 2) {
    cout << 1;
    return 0;
  }
  if (x == 3) {
    cout << 2;
    return 0;
  }
  fibo.push_back(1);
  fibo.push_back(2);
  int n = 2;
  while (1) {
    fibo.push_back(fibo[n - 1] + fibo[n - 2]);
    if (fibo[n] > x) {
      cout << n - 1;
      return 0;
    }
    n++;
  }
  return 0;
}
