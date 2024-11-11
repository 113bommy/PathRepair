#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, sum;
  cin >> b;
  for (a = 1; a <= sqrt(b); a++) {
    if (b % a == 0) {
      if (b / a == a)
        sum += 1;
      else
        sum += 2;
    }
  }
  cout << sum;
}
