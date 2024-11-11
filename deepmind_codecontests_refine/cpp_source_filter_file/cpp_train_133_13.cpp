#include <bits/stdc++.h>
using namespace std;
int main() {
  long long q;
  cin >> q;
  long long numOfPrimes = 0;
  long long ans1 = -1, ans2 = -1;
  long long num = q;
  while (q % 2 == 0) {
    if (numOfPrimes > 2) break;
    numOfPrimes++;
    q /= 2;
    if (ans1 == -1)
      ans1 = 2;
    else if (ans2 == -1)
      ans2 = 2;
  }
  for (long long i = 3; i <= sqrt(q); i++) {
    if (numOfPrimes > 2) break;
    while (q % i == 0) {
      if (numOfPrimes > 2) break;
      numOfPrimes++;
      q /= i;
      if (ans1 == -1)
        ans1 = i;
      else if (ans2 == -1)
        ans2 = i;
    }
  }
  if (q > 2) numOfPrimes++;
  if (numOfPrimes == 0) {
    cout << 1 << endl << 0 << endl;
  } else if (numOfPrimes <= 2)
    cout << 2 << endl;
  else {
    cout << 1 << endl << ans1 * ans2 << endl;
  }
}
