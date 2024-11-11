#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int two, three, five, six, thirtytwo;
  cin >> two >> three >> five >> six;
  long long int use = min(min(two, five), six);
  long long int twofiftysix = 256 * use;
  if (two - use > 0) {
    long long int use2 = min(two - use, three);
    thirtytwo = 32 * use2;
  }
  cout << twofiftysix + thirtytwo << "\n";
  return 0;
}
