#include <bits/stdc++.h>
using namespace std;
int main() {
  long long unsigned int n, k;
  cin >> n >> k;
  long long unsigned int currentCount = 0;
  double squareRoot = sqrt(n);
  long long unsigned int uppperHut = (long long unsigned int)squareRoot;
  bool perfectSquare = (squareRoot - uppperHut == 0.0 ? true : false);
  vector<long long unsigned int> factors;
  for (long long unsigned int i = 1; i <= uppperHut; i++) {
    if (n % i == 0) {
      factors.push_back(i);
      ++currentCount;
    }
    if (currentCount == k) {
      cout << i << endl;
      return 0;
    }
  }
  long long unsigned int startingLimit;
  bool valid;
  startingLimit = currentCount - 1 - (perfectSquare ? 1 : 0);
  if (k > currentCount * 2 - (perfectSquare ? 1 : 0)) {
    valid = false;
  } else {
    valid = true;
  }
  if (valid) {
    for (long long unsigned int i = startingLimit; i >= 0; i--) {
      ++currentCount;
      if (currentCount == k) {
        cout << n / factors.at(i) << endl;
        return 0;
      }
    }
  } else {
    cout << -1 << endl;
    return 0;
  }
}
