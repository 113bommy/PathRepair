#include <bits/stdc++.h>
using namespace std;
int main() {
  int one, two, n1, n2, k1, k2, k;
  cin >> n1 >> n2 >> k1 >> k2;
  if (k1 > k2)
    k = k2;
  else
    k = k1;
  one = n1 - k;
  two = n2 - k;
  if (one >= two)
    cout << "First\n";
  else
    cout << "Second\n";
  return 0;
}
