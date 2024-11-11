#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int b;
  cin >> b;
  long long int count = 0;
  long long int sq = (long long int)sqrt(b);
  for (long long int i = 1; i < sq; i++) {
    if (b % i) {
      count += 2;
    }
  }
  if (sq * sq == b) {
    count += 1;
  } else {
    if ((b % sq) == 0) count += 2;
  }
  cout << count << endl;
  return 0;
}
