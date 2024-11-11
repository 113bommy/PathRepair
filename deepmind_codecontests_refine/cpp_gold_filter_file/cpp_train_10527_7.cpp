#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, answer = 2000000000;
  cin >> n >> k;
  for (int b = 1; b < k; b++) {
    if (n % b == 0) {
      if (answer > n * k / b + b) {
        answer = n * k / b + b;
      }
    }
  }
  cout << answer << endl;
  return 0;
}
